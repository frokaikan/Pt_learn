# Template makefile from $PTII/ptolemy/codegen/java/makefile.in
# $Id$
# The CodeGenerator class subsitutes strings like "model2" with
# the value of parameters and writes the results in the directory
# where the source code is created.
#
# To use your _own_ makefile, create a makefile named "ModelName.mk.in".
# For example, if the model is called Foo, then the code generator
# looks for a makefile template file called "Foo.mk.in" and then
# looks for $PTII/ptolemy/codegen/java/makefile.in.
#
# To compile using this makefile after substitution, run:
#    make -f model2.mk

PTCGLIBRARIES = .;

CLASSPATHSEPARATOR=;

ROOT = .

CLASSPATH = $(PTCGLIBRARIES)$(CLASSPATHSEPARATOR)$(ROOT)

# If the user would like to add compile time options, run with
# make -f model2.mk USER_JAVAC_FLAGS=xxx
# Or, set USER_JAVAC_FLAGS in your environment before executing
# the code generator.  For example, under bash:
# export USER_JAVAC_FLAGS=-J-Xmx2000M; $PTII/bin/ptcg -language java /Users/cxh/ptII/ptolemy/cg/lib/test/auto/Scale_java.xml 
# USER_JAVAC_FLAGS =

MODELCLASS = model2

model2.class: model2.java
	javac -classpath "$(CLASSPATH)" $(WARNING_CC_FLAGS) $(JAVAC_FLAGS) $(USER_JAVAC_FLAGS) model2.java

run: model2.class
	"java" -Xmx3000m -ea -classpath "$(CLASSPATH)" $(MODELCLASS)
