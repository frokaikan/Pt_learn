/* Generated by Ptolemy II (http:_X_FORWARDSLASH_X__X_FORWARDSLASH_X_ptolemy.eecs.berkeley.edu)
Copyright (c) 2005_X_MINUS_X_2016 The Regents of the University of California.
All rights reserved.
Permission is hereby granted_X_COMA_X_ without written agreement and without
license or royalty fees_X_COMA_X_ to use_X_COMA_X_ copy_X_COMA_X_ modify_X_COMA_X_ and distribute this
software and its documentation for any purpose_X_COMA_X_ provided that the above
copyright notice and the following two paragraphs appear in all copies
of this software.
IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY
FOR DIRECT_X_COMA_X_ INDIRECT_X_COMA_X_ SPECIAL_X_COMA_X_ INCIDENTAL_X_COMA_X_ OR CONSEQUENTIAL DAMAGES
ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION_X_COMA_X_ EVEN IF
THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES_X_COMA_X_
INCLUDING_X_COMA_X_ BUT NOT LIMITED TO_X_COMA_X_ THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE
PROVIDED HEREUNDER IS ON AN "AS IS" BASIS_X_COMA_X_ AND THE UNIVERSITY OF
CALIFORNIA HAS NO OBLIGATION TO PROVIDE MAINTENANCE_X_COMA_X_ SUPPORT_X_COMA_X_ UPDATES_X_COMA_X_
ENHANCEMENTS_X_COMA_X_ OR MODIFICATIONS.
*/
public class model2 {
    /* end includeecode */
    /* Generate type resolution code for .model2 */
    // ConstantsBlock from SharedCode.j
    private static final short TYPE_Token = -1;
    // #define PTCG_TYPE_Boolean 5
    private static final short TYPE_Boolean = 5;
    // #define FUNC_new 0
    // #define FUNC_convert 1
    // #define FUNC_delete 2
    // #define FUNC_isCloseTo 3
    public static Token emptyToken; /* Used by _X_STAR_X__delete() and others. */
    // Token Boolean_new (Token thisToken, Token... tokens);  funcHeaderBlock from SharedCode.j
    // Token Boolean_convert (Token thisToken, Token... tokens);  funcHeaderBlock from SharedCode.j
    // Token Boolean_equals (Token thisToken, Token... tokens);  funcHeaderBlock from SharedCode.j
    // Token Boolean_isCloseTo (Token thisToken, Token... tokens);  funcHeaderBlock from SharedCode.j
    /* We share one method between all scalar types so as to reduce code size. */
    static Token scalarDelete(Token token, Token... tokens) {
        /* We need to return something here because all the methods are declared
        * as returning a Token so we can use them in a table of functions.
        */
        return emptyToken;
    }
    static Integer StringtoInteger(String string) {
        return Integer.valueOf(string);
    }
    static Long StringtoLong(String string) {
        return Long.valueOf(string);
    }
    // static String ComplextoString(Token thisToken) {
        //     if (((ComplexCG)thisToken.payload).imag >= 0) {
            //         return Double.toString(((ComplexCG)thisToken.payload).real)
            //                + " + " + Double.toString(((ComplexCG)thisToken.payload).imag) + "i";
        //     } else {
            //         return Double.toString(((ComplexCG)thisToken.payload).real)
            //                + " - " + Double.toString(-((ComplexCG)thisToken.payload).imag) + "i";
        //     }
    // }
    //static String ComplextoString(Token complex) {
        //       return (String)(Complex_toString(complex).payload);
    //}
    static Integer DoubletoInteger(Double d) {
        return Integer.valueOf((int)Math.floor(d.doubleValue()));
    }
    static Double IntegertoDouble(Integer i) {
        return Double.valueOf(i.doubleValue());
    }
    static Long IntegertoLong(int i) {
        return Long.valueOf(i);
    }
    static String IntegertoString(int i) {
        return Integer.toString(i);
    }
    static String LongtoString(long l) {
        return Long.toString(l);
    }
    static String DoubletoString(double d) {
        return Double.toString(d);
    }
    static String BooleantoString(boolean b) {
        return Boolean.toString(b);
    }
    static String UnsignedBytetoString(byte b) {
        return Byte.toString(b);
    }
    private static final int NUM_TYPE = 1;
    private static final int NUM_FUNC = 4;
    //Token (*functionTable[NUM_TYPE][NUM_FUNC])(Token, ...) = {
    //	{Boolean_new, Boolean_convert, scalarDelete, Boolean_equals}
    //};
    int add_Integer_Integer(int a1, int a2) {
        return a1 + a2;
    }
    int subtract_Integer_Integer(int a1, int a2) {
        return a1 - a2;
    }
    // make a new integer token from the given value.
    static Token Boolean_new(boolean b) {
        Token result = new Token();
        result.type = TYPE_Boolean;
        result.payload = Boolean.valueOf(b);
        return result;
    }
    static Token Boolean_convert(Token token, Token... tokens) {
        switch (token.type) {
            case TYPE_Boolean:
            return token;
            default:
            throw new RuntimeException("Boolean_convert(): Conversion from an unsupported type.: " + token.type);
        }
    }
    /* Instead of Boolean_delete(), we call scalarDelete(). */
    static Token Boolean_equals(Token thisToken, Token... tokens) {
        Token otherToken;
        otherToken = tokens[0];
        return Boolean_new(
        ( (Boolean)thisToken.payload && (Boolean)otherToken.payload ) ||
        ( !(Boolean)thisToken.payload && !(Boolean)otherToken.payload ));
    }
    /* end typeResolution code */
    /* end shared code */
    /* model2_Display's input variable declarations. */
    public static int model2_Display_input[] = new int[1];
    /* model2_Ramp's referenced parameter declarations. */
    public static int model2_Ramp_step_;
    /* model2_Display3's input variable declarations. */
    public static int model2_Display3_input[] = new int[1];
    /* model2_AddSubtract's input variable declarations. */
    public static int model2_AddSubtract_plus[] = new int[1];
    public static int model2_AddSubtract_minus[] = new int[1];
    /* Provide the period attribute as constant. */
    public final static double PERIOD = 0.0;
    /* Provide the iteration count. */
    public static int _iteration = 0;
    /* end variable declaration code */
    /* The preinitialization of the director. */
    /* preinitRamp */
    static int model2_Ramp__state;
    int model2_Ramp__LimitedFiringSource_iterationCount = 0;
    /* preinitialize AddSubtract */
    int model2_AddSubtract__result;
    /* end preinitialize code */
    /* end preinitialize method code */
    /* Before appending splitPreinitializeMethodBodyCode_X_LBRACKET_X_0_X_RBRACKET_X_. */
    /* After appending splitPreinitializeMethodBodyCode_X_LBRACKET_X_0_X_RBRACKET_X_. */
    public void preinitialize() throws Exception {
        /* JCG preintialization body code */
    }
    /* Before appending splitVariableInitCode_X_LBRACKET_X_0_X_RBRACKET_X_. */
    /*
    After appending splitVariableInitCode_X_LBRACKET_X_0_X_RBRACKET_X_.
    */
    /* Before appending splitInitializeCode_X_LBRACKET_X_0_X_RBRACKET_X_. */
    /* After appending splitInitializeCode_X_LBRACKET_X_0_X_RBRACKET_X_. */
    /* Before appending initializeEntryCode */
    public void initialize() throws Exception {
        /* After appending initializeEntryCode */
        /* Before appending splitVariableInitCode_X_LBRACKET_X_1_X_RBRACKET_X_. */
        /* Ramp's parameter initialization */
        model2_Ramp_step_ = 3;
        /* After appending splitVariableInitCode_X_LBRACKET_X_1_X_RBRACKET_X_. */
        /* Before appending splitInitializeCode_X_LBRACKET_X_1_X_RBRACKET_X_. */
        /* The initialization of the director. */
        /* initialize Ramp */
        model2_Ramp__state = 0;
        /* After appending splitInitializeCode_X_LBRACKET_X_1_X_RBRACKET_X_. */
        /* Before appending initializeExitCode. */
    }
    public void wrapup() throws Exception {
        /* The wrapup of the director. */
    }
    public static void main(String [] args) throws Exception {
        model2 model = new model2();
        model.preinitialize();
        model.initialize();
        model.execute();
        model.doWrapup();
        System.exit(0);
    }
    // Don't call initialize() here, it is called in main.
    public  void execute()  throws Exception {
        int iteration;
        for (iteration = 0; iteration < 10; iteration ++) {
            if (!run()) {
                break;
            }
        }
    }
    public  boolean run()  throws Exception {
        /* The firing of the StaticSchedulingDirector */
        /* Fire model2_Const */
        {
            int model2_Const__temp;
            model2_Const__temp = 10;
            model2_AddSubtract_minus[0] = model2_Const__temp;
            ;
        }
        /* Begin updateOffset model2_Const_trigger */
        /* Begin updateConnectedPortsOffset model2_Const_output */
        /* End updateConnectedPortsOffset model2_Const_output */
        /* Fire model2_Ramp */
        {
            int temporary = model2_Ramp__state;
            model2_Display3_input[0] = temporary;
            model2_AddSubtract_plus[0] = temporary;
        }
        ;
        model2_Ramp_step_ = 3;
        model2_Ramp__state += (Integer)model2_Ramp_step_;
        /* Begin updateOffset model2_Ramp_trigger */
        /* Begin updateOffset model2_Ramp_init */
        /* Begin updateOffset model2_Ramp_step */
        /* Begin updateConnectedPortsOffset model2_Ramp_output */
        /* End updateConnectedPortsOffset model2_Ramp_output */
        /* Fire model2_AddSubtract */
        model2_AddSubtract__result = 0;
        model2_AddSubtract__result = 0;
        if (true) {
            model2_AddSubtract__result = add_Integer_Integer(model2_AddSubtract__result, model2_AddSubtract_plus[0]);
        }
        if (true) {
            model2_AddSubtract__result = subtract_Integer_Integer(model2_AddSubtract__result, model2_AddSubtract_minus[0]);
        }
        model2_Display_input[0] = model2_AddSubtract__result;
        ;
        /* Begin updateOffset model2_AddSubtract_plus */
        /* End updateOffset model2_AddSubtract_plus */
        /* Begin updateOffset model2_AddSubtract_minus */
        /* End updateOffset model2_AddSubtract_minus */
        /* Begin updateConnectedPortsOffset model2_AddSubtract_output */
        /* End updateConnectedPortsOffset model2_AddSubtract_output */
        /* Fire model2_Display */
        System.out.println("MaximumDisplay: " + model2_Display_input[0]);
        /* Begin updateOffset model2_Display_input */
        /* End updateOffset model2_Display_input */
        /* Fire model2_Display3 */
        System.out.println("RampDisplay: " + model2_Display3_input[0]);
        /* Begin updateOffset model2_Display3_input */
        /* End updateOffset model2_Display3_input */
        /* The postfire of the director. */
        /* postfireRamp */
        model2_Ramp__LimitedFiringSource_iterationCount++;
        if (0 == model2_Ramp__LimitedFiringSource_iterationCount) {
            // Return from run()
            return false;
        }
        ++_iteration;
        return true;
    }
    public void doWrapup() throws Exception {
    }
}
