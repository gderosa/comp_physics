// vim: set ts=2 sts=2 sw=2 et:

#ifdef DEBUG
#include <iostream>
#endif

#include "Polynomial.h"

namespace interpolator 
{

Polynomial::Polynomial( // inherit the constructor
            std::vector< std::pair<double, double> > points ): Base(points)
{
  n = points.length - 1;
}


double Polynomial::p_n(double x)
{
  unsigned int j;
  for (j=0; j<=n; j++) {
    
  }
}


}
