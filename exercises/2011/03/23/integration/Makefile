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

clean:
	rm -fr output
	rm -f *.o */*.o ${EXE}
	rmdir ${BINDIR} 2> /dev/null

extrapolate: ${OUTPUT_DATA}

${OUTPUT_DATA}: ${EXE} 
	ruby ./extrapolate.rb trapezoidal
	ruby ./extrapolate.rb simpson

plot: ${PLOTS}

${PLOTS}: ${OUTPUT_DATA} plot.trapezoidal.gpi plot.simpson.gpi
	gnuplot plot.trapezoidal.gpi
	gnuplot plot.simpson.gpi
