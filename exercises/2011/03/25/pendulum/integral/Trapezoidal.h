// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_TRAPEZOIDAL_H
#define INTEGRAL_TRAPEZOIDAL_H


#include "Base.h"

namespace integral 
{

class Trapezoidal: public Base 
{
public:
  
  Trapezoidal(function::Base * const f): Base(f) {} // inherit the constructor
  
  double compute()
  {
    unsigned int i;
    double sum = 0;

    for(i=0; i<nIntervals; i++) {
      sum += (
        (f(i) + f(i+1)) * deltaX() / 2
      );
    }

    return sum;
  }
};


}

#endif // #ifndef INTEGRAL_TRAPEZOIDAL_H
