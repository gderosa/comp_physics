// vim: set ts=2 sts=2 sw=2 et:

#include <cmath>
#include <iostream>
#include <iomanip>

#include "integral/Trapezoidal.h"

using namespace std;

// Normal distribution, sigma=1, x_0 = 0
double f(double x) 
{
  return (1/sqrt(2*M_PI)) * exp( -(x*x)/2 ); 
}

int main() 
{
  integral::Trapezoidal integral(*f);
  unsigned int n;

  integral.lowerEnd   = -1.0;
  integral.upperEnd   =  1.0;

  cout << setprecision(16);
  cout << setiosflags(ios::left);

  for (n = 4; n <= 2048; n *= 2) { 
    integral.nIntervals = n;
    cout << 
      setw(20) << integral.deltaX()   << 
      setw(20) << integral.compute()  << endl;
  }

  return 0;
}
