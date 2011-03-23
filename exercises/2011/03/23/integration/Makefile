# Tested with GCC on GNU/Linux

CXX=c++
CXXFLAGS=-O3 -ffast-math -ansi ${EXTRA_FLAGS} 
LINK=c++ 
LIBS=-lm
OBJS=main.o \
     integral/Base.o integral/Trapezoidal.o integral/Simpson.o

BINDIR=bin
EXE=${BINDIR}/integration
OUTDIR=output
OUTPUT_DATA= \
	${OUTDIR}/extrapolation.trapezoidal.dat \
	${OUTDIR}/integrals.trapezoidal.dat \
	${OUTDIR}/extrapolation.simpson.dat \
	${OUTDIR}/integrals.simpson.dat
		
PLOTS=${OUTDIR}/plot.trapezoidal.pdf ${OUTDIR}/plot.simpson.pdf

all: exe extrapolate plot

exe: ${EXE}

${EXE}: ${OBJS} ${BINDIR}
	${LINK} ${LIBS} -o ${EXE} ${OBJS}

.o: .h
	${CXX} -c -o $*.o $< 

${BINDIR}:
	mkdir -p ${BINDIR}

bin/interpolator:
	make -f Makefile.interpolator

clean:
	rm -fr output ${BINDIR} || true
	rm -f *.o */*.o || true

extrapolate: ${OUTPUT_DATA}

${OUTPUT_DATA}: ${EXE} bin/interpolator
	mkdir -p ${OUTDIR}	
	bin/integration trapezoidal > output/integrals.trapezoidal.dat
	bin/integration simpson     > output/integrals.simpson.dat
	bin/interpolator 0 0.5 500 < output/integrals.trapezoidal.dat > output/extrapolation.trapezoidal.dat
	bin/interpolator 0 0.5 500 < output/integrals.simpson.dat > output/extrapolation.simpson.dat

plot: ${PLOTS}

${PLOTS}: ${OUTPUT_DATA} plot.trapezoidal.gpi plot.simpson.gpi
	gnuplot plot.trapezoidal.gpi
	gnuplot plot.simpson.gpi
