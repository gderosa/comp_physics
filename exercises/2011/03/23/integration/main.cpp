// vim: set ts=2 sts=2 sw=2 et:

#include <cmath>

#include <iostream>

using namespace std;

// Normal distribution, sigma=1, x_0 = 0
double f(double x) 
{
  return (1/sqrt(2*M_PI)) * exp( -(x*x)/2 );
}

int main() 
{
  cout << f(0.0) << endl;
  return 0;
}
