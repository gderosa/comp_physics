# Tested with GCC on GNU/Linux

CXX=c++
CXXFLAGS=-O3 -ffast-math -ansi
LINK=c++ 
LIBS=-lm
OBJS=main.o integral/Base.o integral/Trapezoidal.o
BINDIR=bin
EXE=${BINDIR}/integration

all: ${EXE}

${EXE}: ${OBJS} ${BINDIR}
	${LINK} ${LIBS} -o ${EXE} ${OBJS}

.o: .h
	${CXX} -c -o $*.o $< 

${BINDIR}:
	mkdir -p ${BINDIR}

clean:
	rm -f *.o ${EXE}

