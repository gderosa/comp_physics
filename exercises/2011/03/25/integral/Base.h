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
  double x(unsigned int i);
  double deltaX();
  double f(unsigned int i);

  Base();
  Base(function::Base *integrand); 

  virtual double compute() {return 0.0;};

protected:
  function::Base * _integrand;
};


}

#endif // #ifndef INTEGRAL_BASE_H
