# Tested with GCC on GNU/Linux

CXX=c++
CXXFLAGS=-O3 -ffast-math -ansi ${EXTRA_FLAGS} 
LINK=c++ 
LIBS=-lm
OBJS=pendulum_multi.o \
		 interpolator/Base.o interpolator/Polynomial.o
BINDIR=bin
EXE=${BINDIR}/pendulum_multi

OUTDIR=output
OUTPUT_DATA= \
	${OUTDIR}/pendulum_multi.dat 
PLOTS=${OUTDIR}/pendulum_multi.pdf 

all: exe plot

exe: ${EXE}

${EXE}: ${OBJS} ${BINDIR}
	${LINK} ${LIBS} -o ${EXE} ${OBJS}

.o: .h
	${CXX} -c -o $*.o $< 

${BINDIR}:
	mkdir -p ${BINDIR}

clean:
	rm -fr output ${BINDIR} || true
	rm -f *.o */*.o || true

${OUTPUT_DATA}: ${EXE} 
	mkdir -p ${OUTDIR}	
	bin/pendulum_multi > ${OUTPUT_DATA}

plot: ${PLOTS}

${PLOTS}: ${OUTPUT_DATA} pendulum_multi.gpi 
	gnuplot pendulum_multi.gpi

