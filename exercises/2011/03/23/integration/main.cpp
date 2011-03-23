// vim: set ts=2 sts=2 sw=2 et:

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "integral/Trapezoidal.h"
#include "integral/Simpson.h"

using namespace std;

// Normal distribution, sigma=1, x_0 = 0
double f(double x) 
{
  return (1/sqrt(2*M_PI)) * exp( -(x*x)/2 ); 
}

int main(int argc, char *argv[]) 
{
  integral::Base * integral;
  unsigned int n;

  if ( (argc == 1) || (strcmp(argv[1], "trapezoidal") == 0) )
    integral = new integral::Trapezoidal(*f);
  else if ( strcmp(argv[1], "simpson") == 0 )
    integral = new integral::Simpson(*f);
  else {
    cerr << "Invalid integration type '" << argv[1] << "'" << endl;
    abort();
  }

  integral->lowerEnd   = -1.0;
  integral->upperEnd   =  1.0;

  cout << setprecision(16);
  cout << setiosflags(ios::left);

  for (n = 4; n <= 512; n *= 2) { 
    integral->nIntervals = n;
    cout << 
      setw(20) << integral->deltaX()   << 
      setw(20) << integral->compute()  << endl;
  }

  delete integral;

  return 0;
}
