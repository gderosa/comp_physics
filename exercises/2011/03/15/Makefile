# Tested with GCC on GNU/Linux

CC=cc -O2
LINK=cc
EXE=cholesky

all: ${EXE}

${EXE}: main.o io.o cholesky.o
	${LINK} -o ${EXE} main.o io.o cholesky.o

.o:
	${CC} -c -o $*.o $< 

clean:
	rm -f *.o ${EXE}

