// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

#include <list>

#include <iostream>

#include "../function/Base.h"

namespace integral 
{

class Binary
{
public:
  unsigned int order;
  std::list<double> values; // Habemus Cache!
  unsigned int nIntervals() {return 1<<order;};
  double lowerEnd;
  double upperEnd;

  Binary(
      function::Base * const integrand,
      const double lowerEnd_, const double upperEnd_,
      const unsigned int initialOrder
  ) :
      _integrand(integrand), 
      lowerEnd(lowerEnd_), upperEnd(upperEnd_),
      order(initialOrder),
      values()
  {
    size_t i;
    for(i = 0; i < (1<<initialOrder) ; i++) {
      values.push_back(discrete_evaluate(i));
    }
    values.push_back((*_integrand)(upperEnd)); 
  } 

  double deltaX()                 
  { 
    return (upperEnd - lowerEnd) / (double)nIntervals(); 
  }

  virtual double compute()        { return 0.0; }

  void refineDiscretization()
  {
    std::list<double>::iterator it = values.begin();
    double x = lowerEnd + deltaX()/2;
    ++it;
    while ( it != values.end() ) {
      values.insert(it, (*_integrand)(x));
      x += deltaX();
      ++it;
    }
    ++order;
  }

protected:
  function::Base * _integrand;

  double discrete_evaluate(const size_t i)
  {
    return (*_integrand)(
        lowerEnd + i * (upperEnd-lowerEnd)/nIntervals()
    );
  }

};


}

#endif // #ifndef INTEGRAL_BASE_H
