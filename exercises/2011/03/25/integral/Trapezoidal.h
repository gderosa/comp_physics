// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_TRAPEZOIDAL_H
#define INTEGRAL_TRAPEZOIDAL_H


#include "Base.h"

namespace integral 
{

template <class FunctionClass>
class Trapezoidal: public Base<FunctionClass> 
{
public:

  Trapezoidal(FunctionClass * f): Base<FunctionClass>(f) {} 

  double compute()
  {
    unsigned int i;
    double sum = 0;

    for(i=0; i<this->nIntervals; i++) {
      sum += (
        (this->f(i) + this->f(i+1)) * this->deltaX() / 2
      );
    }

    return sum;
  }

};


}

#endif // #ifndef INTEGRAL_TRAPEZOIDAL_H
