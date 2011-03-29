// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BINARY_SIMPSON_H
#define INTEGRAL_BINARY_SIMPSON_H

#include <iostream>

#include "Binary.h"

namespace integral 
{

class BinarySimpson: public Binary 
{
public:

  BinarySimpson(
      function::Base * const f, 
      const double lowerEnd, const double upperEnd,
      const unsigned int order
  ): Binary(f, lowerEnd, upperEnd, order) {} // inherit the constructor

  double compute()
  {
    std::list<double>::iterator it = values.begin();
    double sum = *it; 

    ++it;
    while(it != values.end()) { 
      sum += 4.0 * (*it);
      ++it;
      sum += 2.0 * (*it);
      ++it;
    }
    sum -= (*it);

    // // Does not apply
    //if (nIntervals & 1) // odd
    //  trapezoidal_term = deltaX() * ( f(nIntervals-1) + f(nIntervals-2) ) / 2.0;

    return sum * deltaX() / 3.0 ;
  }

};


}

#endif 
