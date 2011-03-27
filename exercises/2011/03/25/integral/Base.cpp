// vim: set ts=2 sts=2 sw=2 et:

#include "Base.h"

namespace integral
{

Base::Base()
{
  _integrand = 0; // Null pointer
}
  
Base::Base(double (*integrand)(double x))
{
  _integrand = integrand; 
}

double Base::x(unsigned int i)
{
  return lowerEnd + i * deltaX();
}

double Base::deltaX()
{
  return (upperEnd - lowerEnd) / nIntervals;
}

double Base::f(unsigned int i)
{
  return (*_integrand)(x(i));
}

}
