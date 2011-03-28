#ifndef FUNCTION_BISECTED_H
#define FUNCTION_BISECTED_H

#include <list>

#include "Base.h"

namespace function
{

// Discretize a function, caching values
struct BinaryValueCache
{
  function::Base * function;
  unsigned int order; // so there are 2**order intervals
  double lowerEnd;
  double upperEnd;
  std::list<double> values;

  BisectMixin(double lowerEnd_, double upperEnd_, unsigned int order_) :
      lowerEnd(lowerEnd_),  upperEnd(upperEnd_), order(order_)
  {
    size_t i;
    for(i=0; i<nIntervals(); i++) {
      values.push_back(discrete_evaluate(i));
    }
    values.push_back(function(upperEnd)); 
  }

  size_t nIntervals()                       { return 1 << order; }
  double discrete_evaluate(size_t i) 
  {
    return function(
        lowerEnd + i * (upperEnd-lowerEnd)/nIntervals()
    );
  }
  double deltaX() {return (upperEnd-lowerEnd)/nIntervals();}

  void refine()
  {
    std::list<double>::iterator it = values.begin();
    double x = lowerEnd + deltaX()/2;
    while ( it != values.end() ) {
      values.insert(it, function(x));
      x += deltaX();
      ++it;
    }
    order++;
  }

};

}

#endif 
