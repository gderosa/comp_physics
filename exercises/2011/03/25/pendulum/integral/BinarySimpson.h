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

  // inherit the constructor
  BinarySimpson( 
      function::Base * const f, 
      const double lowerEnd, const double upperEnd,
      const unsigned int order, const unsigned int maxOrder
  ): Binary(f, lowerEnd, upperEnd, order, maxOrder) {} 

  // inherit the destructor
  //~BinarySimpson(): ~Binary() {}

  double compute()
  {
    double sum = values[0];
    size_t i;
    size_t stepsInDiscreteCache = 1 << (maxOrder - order) ;
    for (
        i = stepsInDiscreteCache;
        i < maxNIntervals() ;
        i += 2 * stepsInDiscreteCache
    )
      sum += ( 4.0 * values[i] + 2.0 * values[i + stepsInDiscreteCache]) ;
    sum -= values[maxNIntervals()];

    return sum * deltaX() / 3.0 ;
  }

};


}

#endif 
