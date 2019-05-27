#include "_ptTypes.h"
Token emptyToken;
Token* convert(Token* t, char type) {
    if (t->type == type)
    return t;
    if (type == TYPE_Boolean) {
        return Boolean_convert(t);
    }
    if (type == TYPE_Double) {
        return Double_convert(t);
    }
    if (type == TYPE_Int) {
        return Int_convert(t);
    }
    return NULL;
}
char* InttoString (int i) {
    char* string = (char*) malloc(sizeof(char) * 12);
    sprintf((char*) string, "%d", i);
    return string;
}
char* LongtoString (long long l) {
    char* string = (char*) malloc(sizeof(char) * 22);
    sprintf(string, "%lld", l);
    return string;
}
char* DoubletoString (double d) {
    int index;
    char* string = (char*) malloc(sizeof(char) * 20);
    sprintf(string, "%.14g", d);
    // Make sure that there is a decimal point.
    if (strrchr(string, '.') == NULL) {
        index = strlen(string);
        if (index == 20) {
            string = (char*) realloc(string, sizeof(char) * 22);
        }
        string[index] = '.';
        string[index + 1] = '0';
        string[index + 2] = '\0';
    }
    return string;
}
char* BooleantoString (boolean b) {
    char *results;
    if (b) {
        // AVR does not have strdup
        results = (char*) malloc(sizeof(char) * 5);
        strcpy(results, "true");
    } else {
        results = (char*) malloc(sizeof(char) * 6);
        strcpy(results, "false");
    }
    return results;
}
char* UnsignedBytetoString (unsigned char b) {
    char* string = (char*) malloc(sizeof(char) * 3);
    sprintf(string, "%d", (int) b);
    return string;
}
/* We share one method between all scalar types so as to reduce code size. */
Token* scalarDelete(Token *token, ...) {
    /* We need to return something here because all the methods are declared
    * as returning a Token so we can use them in a table of functions.
    */
    return NULL;
}
// make a new integer token from the given value.
Token* Int_new(int i) {
    Token* result = calloc(1, sizeof(Token));
    result->type = TYPE_Int;
    result->payload.Int = i;
    return result;
}
int add_Int_Int(int a1, int a2) {
    return a1 + a2;
}
int subtract_Int_Int(int a1, int a2) {
    return a1 - a2;
}
Token* Boolean_convert(Token* token, ...) {
    switch (token->type) {
        // FIXME: not finished
        default:
        fprintf(stderr, "Boolean_convert(): Conversion from an unsupported type. (%d)", token->type);
        break;
    }
    token->type = TYPE_Boolean;
    return token;
}
/* Instead of Boolean_delete(), we call scalarDelete(). */
// Boolean Tokens can only be true or false and
// are immutable, so we have just two Booleans
Token* Boolean_False;
Token* Boolean_True;
// make a new integer token from the given value.
Token* Boolean_new(boolean b) {
    // Uncomment the next line to try the two Boolean apprach
    //#define TWO_BOOLEANS
    #ifdef TWO_BOOLEANS
    if (b) {
        if (Boolean_True == NULL) {
            Boolean_True = malloc(sizeof(Token));
            Boolean_True->type = TYPE_Boolean;
            Boolean_True->payload.Boolean = b;
        }
        return Boolean_True;
    } else {
        if (Boolean_False == NULL) {
            Boolean_False = malloc(sizeof(Token));
            Boolean_False->type = TYPE_Boolean;
            Boolean_False->payload.Boolean = b;
        }
        return Boolean_False;
    }
    #else
    // This code mallocs a token each time
    // it is called.
    Token* result = malloc(sizeof(Token));
    result->type = TYPE_Boolean;
    result->payload.Boolean = b;
    return result;
    #endif
}
Token* Boolean_equals(Token* thisToken, ...) {
    va_list argp;
    Token* otherToken;
    va_start(argp, thisToken);
    otherToken = va_arg(argp, Token*);
    va_end(argp);
    return Boolean_new(( thisToken->payload.Boolean && otherToken->payload.Boolean ) ||
    ( !thisToken->payload.Boolean && !otherToken->payload.Boolean ));
}
Token* Double_convert(Token* token, ...) {
    switch (token->type) {
        #ifdef TYPE_String
        case TYPE_String:
        // FIXME: Is this safe?
        token->type = TYPE_Double;
        if (sscanf(token->payload.String, "%lg", &token->payload.Double) != 1) {
            fprintf(stderr, "Double_convert(): failed to convert \"%s\" to a Double\n", token->payload.String);
            exit(-1);
        }
        break;
        #endif
        #ifdef TYPE_Int
        case TYPE_Int:
        token->type = TYPE_Double;
        token->payload.Double = InttoDouble(token->payload.Int);
        break;
        #endif
        // FIXME: not finished
        default:
        fprintf(stderr, "Double_convert(): Conversion from an unsupported type. (%d)\n", token->type);
        exit(-1);
        break;
    }
    token->type = TYPE_Double;
    return token;
}
/* Instead of Double_delete(), we call scalarDelete(). */
Token* Double_isCloseTo(Token *thisToken, ...) {
    va_list argp;
    Token* otherToken;
    Token* tolerance;
    va_start(argp, thisToken);
    otherToken = va_arg(argp, Token*);
    tolerance = va_arg(argp, Token*);
    va_end(argp);
    return Boolean_new(fabs(thisToken->payload.Double - otherToken->payload.Double) < tolerance->payload.Double);
}
Token* Int_convert(Token* token, ...) {
    switch (token->type) {
        #ifdef TYPE_Double
        case TYPE_Double:
        token->payload.Int = DoubletoInt(token->payload.Double);
        break;
        #endif
        // FIXME: not finished
        default:
        fprintf(stderr, "Int_convert(): Conversion from an unsupported type. (%d)\n", token->type);
        break;
    }
    token->type = TYPE_Int;
    return token;
}
/* Instead of Int_delete(), we call scalarDelete(). */
Token* Int_isCloseTo(Token* thisToken, ...) {
    va_list argp;
    Token* otherToken;
    Token* tolerance;
    va_start(argp, thisToken);
    otherToken = va_arg(argp, Token*);
    tolerance = va_arg(argp, Token*);
    va_end(argp);
    return Boolean_new(abs(thisToken->payload.Int - otherToken->payload.Int) < tolerance->payload.Double);
}
Token* (*functionTable[NUM_TYPE][NUM_FUNC])(Token*, ...)= {
{Boolean_convert, scalarDelete, Boolean_equals},
{Double_convert, scalarDelete, Double_isCloseTo},
{Int_convert, scalarDelete, Int_isCloseTo}
};
