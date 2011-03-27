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

class PendulumFunction
{
public:
  double theta_0;

  PendulumFunction(double theta_0_) {theta_0 = theta_0_;}

  // integral in ex 3.16 Pang
  double operator()(double theta) 
  {
    return 1 / sqrt( cos(theta) - cos(theta_0) ); 
  }
};

double integrate(double theta_0) 
{
  PendulumFunction f(theta_0);
  integral::Simpson<PendulumFunction> integral(&f);
  unsigned int n; 
  vector< pair<double, double> > extrapolation_points;

  integral.lowerEnd = 0.0;

  for (n = (1 << 8); n < (1 << 22); n *= 2) { 
    integral.nIntervals = n - 1;
    // exclude the last subinterval, where the f diverges
    integral.upperEnd = theta_0 * ((double)(n - 1)/(double)n); 
    pair<double, double> point;
    point.first   = integral.deltaX();
    point.second  = integral.compute();
    extrapolation_points.push_back(point);
  }

  interpolator::Polynomial intpl(extrapolation_points);
  return intpl.interpolate(0.0);
}

int main(int argc, char *argv[]) 
{
  cout << setprecision(12);

  cout << 
    "# Expected value for small oscillations: " << 
    M_PI/sqrt(2) << " (PI/sqrt(2))" << endl;

  unsigned int n = 4; 
  double theta_0;
  do {
    theta_0 = M_PI/n ; // PI/(powers of 2) 
    cout << 
      setw(19) << theta_0             << 
      setw(19) << integrate(theta_0)  << 
      setw(19) << " # theta_0 = PI/"  << n << 
      endl;
    n *= 2;
  } while(theta_0 > M_PI/128); 

  return 0;
}
