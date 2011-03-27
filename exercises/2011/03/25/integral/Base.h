// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

namespace integral 
{

template <class FunctionClass>
class Base 
{
public:
  unsigned int  nIntervals;
  double        lowerEnd;
  double        upperEnd;

  double x(unsigned int i)  { return lowerEnd + i * deltaX();             }
  double deltaX()           { return (upperEnd - lowerEnd) / nIntervals;  }
  double f(unsigned int i)  { return (*_integrand)(x(i));                 }

  Base()                          { _integrand = 0;           }
  Base(FunctionClass * integrand) { _integrand = integrand;   } 

  virtual double compute()        { return 0.0;               } 

protected:
  FunctionClass * _integrand; 
};




}

#endif // #ifndef INTEGRAL_BASE_H
