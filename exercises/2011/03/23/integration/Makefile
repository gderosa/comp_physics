# Tested with GCC on GNU/Linux

CXX=c++
CXXFLAGS=-O3 -ffast-math -ansi ${EXTRA_FLAGS} 
LINK=c++ 
LIBS=-lm
OBJS=main.o \
     integral/Base.o integral/Trapezoidal.o \
     interpolator/Base.o interpolator/Polynomial.o
BINDIR=bin
EXE=${BINDIR}/integration
OUTDIR=output
OUTPUT_DATA=${OUTDIR}/extrapolation.dat ${OUTDIR}/integrals.dat
PLOTS=${OUTDIR}/plot.pdf

all: exe

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

#plot: ${PLOTS}
#
#${PLOTS}: output/extrapolation.dat output/integrals.dat plot.gpi
#	gnuplot plot.gpi
