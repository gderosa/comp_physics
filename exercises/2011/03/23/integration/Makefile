# Tested with GCC on GNU/Linux

CXX=c++
CXXFLAGS=-O3 -ffast-math -ansi
LINK=c++ 
LIBS=-lm
OBJS=main.o 
EXE=integration

all: ${EXE}

${EXE}: ${OBJS}
	${LINK} ${LIBS} -o ${EXE} ${OBJS}

.o:
	${CXX} -c -o $*.o $< 

clean:
	rm -f *.o ${EXE}

