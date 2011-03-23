// vim: set ts=2 sts=2 sw=2 et:

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

#include "integral/Trapezoidal.h"
#include "interpolator/Polynomial.h"

using namespace std;

// Normal distribution, sigma=1, x_0 = 0
double f(double x) 
{
  return (1/sqrt(2*M_PI)) * exp( -(x*x)/2 ); 
}

int main() 
{
  vector< pair<double, double> > integralsByH;

  integral::Trapezoidal integral(*f);
  unsigned int n;

  integral.lowerEnd   = -1.0;
  integral.upperEnd   =  1.0;

  cout << setprecision(16);
  cout << setiosflags(ios::left);

  for (n = 4; n <= 512; n *= 2) { 
    integral.nIntervals = n;
    integralsByH.push_back( 
      *(new pair<double, double>( 
        integral.deltaX(), integral.compute() 
      )) 
    ); 
  }

  interpolator::Polynomial interpolator(integralsByH);

  cout << interpolator.interpolate(0.0) << endl;

  return 0;
}
