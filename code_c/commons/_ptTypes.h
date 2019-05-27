#ifndef NO_MODEL2_TYPES_H
#define NO_MODEL2_TYPES_H
#include <stdio.h>
#include <stdlib.h>
/* Define _BSD_SOURCE so that string.h includes a declaration for strdup under RHEL. */
#define _BSD_SOURCE
#include <string.h>
#include <math.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include "pbl.h"
#define SDFDIRECTOR 2
// Constants.
#define MISSING 0
// boolean for AVR.  A mess.  I'm sorry...
#ifndef __AVR__
typedef unsigned char boolean;
#else
#ifndef  __cplusplus
typedef unsigned char boolean;
#else
typedef uint8_t boolean;
#endif
#endif
#define DO_NOT_CALL_EXIT
#ifdef DO_NOT_CALL_EXIT
#ifdef PTJNI
extern void throwInternalErrorException();
#define ptExit(x) throwInternalErrorException()
#else /* PTJNI */
#define ptExit(x) {}
#endif /* PTJNI */
#else /* DO_NOT_CALL_EXIT */
#define ptExit(x) exit(x)
#endif /* DO_NOT_CALL_EXIT */
typedef char* string;
/* Infinity is a valid Ptolemy identifier. */
#ifdef __AVR__
#define Infinity INFINITY
#else
#define Infinity HUGE_VAL
#endif
#ifdef __linux__
/* Linux tends to have NAN. */
#define NaN (__builtin_nanf (""))
#else /*linux*/
#define NaN nanf(0)
#endif /*linux*/
#define false 0
#define true 1
typedef struct Actor Actor;
typedef struct CompositeActor CompositeActor;
typedef struct IOPort IOPort;
typedef struct Receiver Receiver;
typedef struct Director Director;
typedef double Time;
#define TYPE_Token -1
#define TYPE_Unknown -1
#define TYPE_Scalar -1
#define TYPE_Boolean 0
#define TYPE_Double 1
#define TYPE_Int 2
#define FUNC_convert 0
#define FUNC_delete 1
#define FUNC_isCloseTo 2
typedef struct token Token;
typedef boolean BooleanToken;
typedef double DoubleToken;
typedef int IntToken;
// Token structure containing the specified types.
struct token {         // Base type for tokens.
    char type;         // TYPE field has to be the first field.
    union typeMembers {
        // type member declarations [i.e. Type1Token Type1;]
        BooleanToken Boolean;
        DoubleToken Double;
        IntToken Int;
    } payload;
};
extern Token emptyToken;
Token* convert(Token* t, char type);
Token* Boolean_new(boolean b);
Token* Double_new(double d);
Token* Int_new(int i);
#define StringtoInt atoi
#define StringtoDouble atof
#define StringtoLong atol
#define DoubletoInt (int)
#define InttoDouble (double)
#define InttoLong (long)
char* InttoString (int i);
char* LongtoString (long long l);
char* DoubletoString (double d);
char* BooleantoString (boolean b);
char* UnsignedBytetoString (unsigned char b);
// functionHeader:
Token* Boolean_convert (Token *thisToken, ...);
Token* Boolean_equals (Token *thisToken, ...);
// functionHeader:
Token* Boolean_equals (Token *thisToken, ...);
// functionHeader:
Token* Double_convert (Token *thisToken, ...);
// functionHeader:
Token* Double_isCloseTo (Token *thisToken, ...);
// functionHeader:
Token* Int_convert (Token *thisToken, ...);
// functionHeader:
Token* Int_isCloseTo (Token *thisToken, ...);
Token* scalarDelete(Token *token, ...);
int add_Int_Int(int a1, int a2) ;
int subtract_Int_Int(int a1, int a2) ;
#define NUM_TYPE 3
#define NUM_FUNC 3
extern Token* (*functionTable[NUM_TYPE][NUM_FUNC])(Token*, ...);
#endif
