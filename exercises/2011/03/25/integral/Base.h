// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

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
  Base(double (*integrand)(double x));

  virtual double compute() {return 0.0;};

protected:
  double (*_integrand)(double x);
};


}

#endif // #ifndef INTEGRAL_BASE_H
