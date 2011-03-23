// vim: set ts=2 sts=2 sw=2 et:

#ifdef DEBUG
#include <iostream>
#endif

#include "Polynomial.h"

namespace interpolator 
{

Polynomial::Polynomial( // inherit the constructor
            std::vector< std::pair<double, double> > &points_ ): Base(points_)
{
  n = points.size() - 1;
}


std::vector<double> Polynomial::p_n(double x_)
{
  unsigned int j, k;
  std::vector<double> p_n_(n, 0.0);

  for (j=0; j<=n; j++) {
    p_n_[j] = 1.0;
    for (k=0; k<=n; k++) {
      if (k == j)
        continue;
      p_n_[j] *= (
        (x_ - x(k)) / (x(j) - x(k))
      );
    }
  }
  return p_n_;
}

double Polynomial::interpolate(double x_)
{
  double sum = 0.0;
  int j;

  for (j=0; j<=n; j++) {
    sum += y(j) * p_n(x_)[j] ;  
  }

  return sum;
}


}
