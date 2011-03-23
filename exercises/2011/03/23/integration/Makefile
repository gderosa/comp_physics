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
OUTPUT_DATA=${OUTDIR}/extrapolation.dat ${OUTDIR}/integrals.dat
PLOTS=${OUTDIR}/plot.pdf

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
	ruby ./extrapolate.rb

plot: ${PLOTS}

${PLOTS}: output/extrapolation.dat output/integrals.dat plot.gpi
	gnuplot plot.gpi
