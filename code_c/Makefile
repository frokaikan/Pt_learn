CC = gcc
CXX = g++
MODEL = model2
FLAGS = -w -O3 -ggdb -fPIC -I_$(MODEL) -Icommons
ALL_C_FILES = $(wildcard _$(MODEL)/*.c) $(wildcard commons/*.c)
ALL_O_FILES = $(ALL_C_FILES:.c=.o)
DEL = del /Q

.PHONY : all
all : $(MODEL)_Main.exe

_$(MODEL)/%.o : _$(MODEL)/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	
commons/%.o : commons/%.c
	$(CC) $(FLAGS) -c -o $@ $<
	
model.dll : $(ALL_O_FILES)
	$(CC) $(FLAGS) -shared -o $@ $^
	
$(MODEL)_Main.exe : $(MODEL)_Main.c $(MODEL)_Main.h model.dll
	$(CC) $(FLAGS) -o $@ $< -L. -lmodel
	
.PHONY : run
run : $(MODEL)_Main.exe
	.\\$(MODEL)_Main.exe
	
.PHONY : clean
clean :
	-$(DEL) _$(MODEL)\*.o
	-$(DEL) commons\*.o
	-$(DEL) model.dll
	-$(DEL) $(MODEL)_Main.exe
	
.PHONY : clean-cache
clean-cache :
	-$(DEL) _$(MODEL)\*.o
	-$(DEL) commons\*.o