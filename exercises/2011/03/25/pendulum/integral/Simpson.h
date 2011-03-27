// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_SIMPSON_H
#define INTEGRAL_SIMPSON_H


#include "Base.h"

namespace integral 
{

class Simpson: public Base 
{
public:

  Simpson(function::Base * const f): Base(f) {} // inherit the constructor

  double compute()
  {
    unsigned int j;
    double sum = 0;
    double trapezoidal_term = 0;

    for(j = 0; j < (nIntervals/2); j++) { // integers: 11/2 = 5
      sum += (
              f(2*j)      +
        4.0 * f(2*j + 1)  +
              f(2*j + 2)
      );
    }

    if (nIntervals & 1) // odd
      trapezoidal_term = deltaX() * ( f(nIntervals-1) + f(nIntervals-2) ) / 2.0;

    return sum * (deltaX()/3.0) + trapezoidal_term;
  }

};


}

#endif // #ifndef INTEGRAL_TRAPEZOIDAL_H
