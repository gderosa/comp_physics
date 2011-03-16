# Tested with GCC on GNU/Linux

CC=cc -O2
LINK=cc 
LIBS=-lm
EXE=cholesky

all: ${EXE}

${EXE}: main.o io.o cholesky.o
	${LINK} ${LIBS} -o ${EXE} main.o io.o cholesky.o

.o:
	${CC} -c -o $*.o $< 

clean:
	rm -f *.o ${EXE}

