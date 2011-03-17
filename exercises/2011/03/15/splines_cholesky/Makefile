# Tested with GCC on GNU/Linux

CC=cc
CFLAGS=-O2 -ansi
LINK=cc 
LIBS=-lm
OBJS=main.o io.o splines_cholesky.o
EXE=splines_cholesky

all: ${EXE}

${EXE}: main.o io.o splines_cholesky.o
	${LINK} ${LIBS} -o ${EXE} ${OBJS}

.o:
	${CC} -c -o $*.o $< 

clean:
	rm -f *.o ${EXE}

