// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_SIMPSON_H
#define INTEGRAL_SIMPSON_H


#include "Base.h"

namespace integral 
{

template <class FunctionClass>
class Simpson: public Base<FunctionClass> 
{
public:

  Simpson(FunctionClass * f): Base<FunctionClass>(f) {} 

  double compute()
  {
    unsigned int j;
    double sum = 0;
    double trapezoidal_term = 0;

    for(j = 0; j < (this->nIntervals/2); j++) { // integers: 11/2 = 5
      sum += (
              this->f(2*j)      +
        4.0 * this->f(2*j + 1)  +
              this->f(2*j + 2)
      );
    }

    unsigned int n = this->nIntervals;
    if (n & 1) // odd
      trapezoidal_term = this->deltaX() * ( this->f(n-1) + this->f(n-2) ) / 2.0;

    return sum * (this->deltaX()/3.0) + trapezoidal_term;
  }
};


}

#endif // #ifndef INTEGRAL_TRAPEZOIDAL_H
