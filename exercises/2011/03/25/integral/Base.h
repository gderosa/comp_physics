// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

#include "../function/Base.h"

namespace integral 
{

class Base 
{
public:
  unsigned int nIntervals;
  double lowerEnd;
  double upperEnd;

  Base()                          { _integrand = 0; /* NULL */                } 
  Base(function::Base *integrand) { _integrand = integrand;                   }

  double x(unsigned int i)        {return lowerEnd + i * deltaX();            } 
  double deltaX()                 {return (upperEnd - lowerEnd) / nIntervals; }
  double f(unsigned int i)        {return (*_integrand)(x(i));                }


  virtual double compute()        { return 0.0;                               }

protected:
  function::Base * _integrand;
};


}

#endif // #ifndef INTEGRAL_BASE_H
