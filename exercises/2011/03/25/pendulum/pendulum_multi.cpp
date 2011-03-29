// vim: set ts=2 sts=2 sw=2 et:

#include <cmath>
#include <iomanip>
#include <iostream>

#include "function/Base.h"
//#include "integral/Trapezoidal.h"
#include "integral/BinarySimpson.h"
#include "interpolator/Polynomial.h"

using namespace std;

// integral in ex 3.16 Pang
struct PendulumIntegrand : public function::Base
{
  double theta_0;

  PendulumIntegrand(const double theta_0_) : theta_0(theta_0_) {} 

  double operator()(const double theta) 
  {
    return 1 / sqrt( cos(theta) - cos(theta_0) );
  }
};

double integrate(const double theta_0) 
{
  PendulumIntegrand f(theta_0);
  double epsilon = 1e-14;
  integral::BinarySimpson binaryIntegral(&f, 0.0, theta_0 - epsilon, 8, 22);
  vector< pair<double, double> > extrapolation_points;

  while (binaryIntegral.order < binaryIntegral.maxOrder) { 
    pair<double, double> point(
        binaryIntegral.deltaX(), binaryIntegral.compute() 
    );
    extrapolation_points.push_back(point);
    binaryIntegral.refineDiscretization();
  }

  interpolator::Polynomial intpl(extrapolation_points);
  return intpl.interpolate(0.0);
}

int main(const int argc, const char *argv[]) 
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
      setw(19) << theta_0       << 
      setw(19) << integrate(theta_0)   << 
      setw(19) << " # theta_0 = PI/" << n << 
      endl;
    n *= 2;
  } while(theta_0 > M_PI/128); 

  return 0;
}
