// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

#include <cstdlib>

#include <iostream>

#include "../function/Base.h"

namespace integral 
{

class Binary
{
public:
  unsigned int order;
  unsigned int maxOrder;
  
  // Cache!
  //std::list<double> values; 
  
  // Cache!
  double * values; // C arrays should be faster?

  unsigned int nIntervals()     {return 1<<order;};
  unsigned int maxNIntervals()  {return 1<<maxOrder;};
  double lowerEnd;
  double upperEnd;

  Binary(
      function::Base * const integrand,
      const double lowerEnd_, const double upperEnd_,
      const unsigned int initialOrder, const unsigned int maxOrder_
  ) :
      _integrand(integrand), 
      lowerEnd(lowerEnd_), upperEnd(upperEnd_),
      order(initialOrder), maxOrder(maxOrder_)
  {
    values = (double*)std::malloc( ( maxNIntervals() + 1) * sizeof(double) );
    // store the first
    values[0] = discrete_evaluate(0); 
    // store the others
    size_t stepsInDiscreteCache = 1 << (maxOrder - order) ;
    size_t i;
    for (
        i = stepsInDiscreteCache; 
        i < maxNIntervals() ; 
        i += stepsInDiscreteCache
    ) {
      values[i] = discrete_evaluate(i);
    }
    // store the last
    values[maxNIntervals()] = ((*_integrand)(upperEnd)); 
  } 

  ~Binary() 
  {
    std::free(values);
  }

  double deltaX()                 
  { 
    return (upperEnd - lowerEnd) / (double)nIntervals(); 
  }

  virtual double compute()        { return 0.0; }

  void refineDiscretization()
  {
    if (order < maxOrder) {
      // 
      // _ = uninitialized
      // * = filled
      //
      // * _ _ _ * _ _ _ * // before 
      // * _ * _ * _ * _ * // after  
      size_t stepsInDiscreteCache = 1 << (maxOrder - order) ;
      size_t i;
      for (
          i = stepsInDiscreteCache/2;
          i < maxNIntervals() ;
          i += stepsInDiscreteCache
      ) {
        values[i] = discrete_evaluate(i);
      }
    } else
      throw "Couldn't refineDiscretization() !!";

    ++order;
  }

protected:
  function::Base * _integrand;

  double discrete_evaluate(const size_t i)
  {
    return (*_integrand)(
        lowerEnd + i * (upperEnd-lowerEnd)/maxNIntervals()
    );
  }

};


}

#endif // #ifndef INTEGRAL_BASE_H
