# Simple makefile
#
# 1) If you want gcov coverage enable the PLFAGS option and rebuild all
# 2)
#
CC    =gcc
LINK  =gcc
DEBUG =-g
#PFLAGS=-fprofile-arcs -ftest-coverage
CFLAGS=-c -Wall -pedantic $(PFLAGS)
LFLAGS=$(PFLAGS)

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness

# Code checking
CODE_CHECK=splint
CODE_CHECK_ARGS=-showfunc -incondefs

OBJS  = main.o stack.o trap.o test01.o


all:	stack.exe splint-it-target

stack.exe:	$(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) -o stack.exe

main.o:		main.c
	$(CC) $(CFLAGS) $(DEBUG) main.c -o main.o
stack.o:	stack.c
	$(CC) $(CFLAGS) $(DEBUG) stack.c -o stack.o
trap.o:		trap.c
	$(CC) $(CFLAGS) $(DEBUG) trap.c -o trap.o
test01.o:	test01.c
	$(CC) $(CFLAGS) $(DEBUG) test01.c -o test01.o

splint-it-target:
	$(CODE_CHECK) $(CODE_CHECK_ARGS) main.c  
	$(CODE_CHECK) $(CODE_CHECK_ARGS) trap.c   
#	$(CODE_CHECK) $(CODE_CHECK_ARGS) test01.c
#	$(CODE_CHECK) $(CODE_CHECK_ARGS) stack.c     

clean:
	rm -f stack.exe
	rm -f stack.o
	rm -f test01.o
	rm -f main.o
	rm -f trap.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f core

#
# Fin
#

