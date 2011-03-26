# Tested with GCC on GNU/Linux

CXX=c++
CXXFLAGS=-O3 -ffast-math -ansi ${EXTRA_FLAGS} 
LINK=c++ 
LIBS=-lm
OBJS=main.o \
		 discrete/uniform/Function.o discrete/uniform/Variable.o \
     integral/Base.o integral/Trapezoidal.o integral/Simpson.o \
		 interpolator/Base.o interpolator/Polynomial.o

BINDIR=bin
EXE=${BINDIR}/pendulum

#OUTDIR=output
#OUTPUT_DATA= \
#	${OUTDIR}/extrapolation.pendulum.dat \
#	${OUTDIR}/integrals.pendulum.dat \
		
#PLOTS=${OUTDIR}/plot.pendulum.pdf 

all: exe 

exe: ${EXE}

${EXE}: ${OBJS} ${BINDIR}
	${LINK} ${LIBS} -o ${EXE} ${OBJS}

.o: .h
	${CXX} -c -o $*.o $< 

${BINDIR}:
	mkdir -p ${BINDIR}

#bin/interpolator:
#	make -f Makefile.interpolator

clean:
	rm -fr output ${BINDIR} || true
	rm -f *.o */*.o */*/*.o || true

#extrapolate: ${OUTPUT_DATA}

#${OUTPUT_DATA}: ${EXE} bin/interpolator
#	mkdir -p ${OUTDIR}	
#	bin/pendulum > output/integrals.pendulum.dat
#	bin/interpolator 0 1e-4 1000 < output/integrals.pendulum.dat > output/extrapolation.pendulum.dat

#plot: ${PLOTS}

#${PLOTS}: ${OUTPUT_DATA} plot.pendulum.gpi 
#	gnuplot plot.pendulum.gpi

