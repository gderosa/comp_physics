# Tested with GCC on GNU/Linux

CC=cc -O2
LINK=cc
EXE=cholesky

all:
	${CC} -c main.c
	${CC} -c io.c
	${CC} -c cholesky.c
	${LINK} -o ${EXE} main.o io.o cholesky.o

clean:
	rm -f *.o ${EXE}
