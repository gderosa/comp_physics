// vim: set ts=2 sts=2 sw=2 et:

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "integral/Trapezoidal.h"
#include "integral/Simpson.h"

using namespace std;

static const double tetha_0[] = {
  M_PI/4, M_PI/8, M_PI/16, M_PI/32, M_PI/64, M_PI/128
};

// integral in ex 3.16 Pang
double f(double theta) 
{
  return 1 / sqrt( cos(theta) - cos(tetha_0[0]) ); 
}

int main(int argc, char *argv[]) 
{
  integral::Trapezoidal integral(*f);
  unsigned int n; 

  integral.lowerEnd = 0.0;

  cout << setprecision(16);
  cout << setiosflags(ios::left);

  for (n = (1 << 12); n < (1 << 21); n *= 2) { 
    integral.nIntervals = n - 1;
    // exclude the last subinterval, where the f diverges
    integral.upperEnd = tetha_0[0] * ((double)(n - 1)/(double)n); 
    cout << 
      setw(24) << integral.deltaX()   <<
      setw(24) << integral.compute()  << endl;
  }

  return 0;
}
