// vim: set ts=2 sts=2 sw=2 et:

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "integral/Trapezoidal.h"
#include "integral/Simpson.h"
#include "interpolator/Polynomial.h"

using namespace std;

static const double tetha_0[] = {
  M_PI/4, M_PI/8, M_PI/16, M_PI/32, M_PI/64, M_PI/128
};

// integral in ex 3.16 Pang
double f(double theta) 
{
  return 1 / sqrt( cos(theta) - cos(tetha_0[0]) ); 
}

double integrate(double tetha_0) 
{
  integral::Trapezoidal integral(*f);
  unsigned int n; 
  vector< pair<double, double> > extrapolation_points;

  integral.lowerEnd = 0.0;

  for (n = (1 << 13); n < (1 << 21); n *= 2) { 
    integral.nIntervals = n - 1;
    // exclude the last subinterval, where the f diverges
    integral.upperEnd = tetha_0 * ((double)(n - 1)/(double)n); 
    pair<double, double> point;
    point.first   = integral.deltaX();
    point.second  = integral.compute();
    extrapolation_points.push_back(point);
  }

  interpolator::Polynomial intpl(extrapolation_points);
  return intpl.interpolate(0);
}

int main(int argc, char *argv[]) 
{
  int i;
  for (i = 0; i < 6; i++) { 
    cout << tetha_0[i] << "\t" << integrate(tetha_0[i]) << endl;
  }

  return 0;
}
