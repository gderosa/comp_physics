// vim: set ts=2 sts=2 sw=2 et:

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>

#include "discrete/uniform/Function.h"
#include "integral/Trapezoidal.h"
#include "interpolator/Polynomial.h"

using namespace std;

// Integrand in ex 3.16 Pang.
struct PendulumIntegrand : public discrete::uniform::Function 
{
  double theta_0;
  PendulumIntegrand(double theta_0_) {
    theta_0 = theta_0_;
  }
  double operator()(double theta) {
    return 1.0 / sqrt( cos(theta) - cos(theta_0) );
  }
};

double integrate(double theta_0) 
{
  PendulumIntegrand integrand(theta_0);
  unsigned int n; 
  vector< pair<double, double> > extrapolation_points;

  integrand.setLowerEnd(0.0);

  for (n = (1 << 4); n < (1 << 10); n *= 2) { 

    integrand.setNIntervals(n - 1);
    // exclude the last subinterval, where the f diverges
    integrand.setUpperEnd( theta_0 * ((double)(n - 1)/(double)n) );  
    
    integral::Trapezoidal integral(integrand);

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
  unsigned int i;
  for (i = 4; i <= 128; i *= 2) { 
    cout << i << "\t" << integrate(M_PI/(double)i) << endl;
  }

  return 0;
}
