// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

namespace integral 
{

class Base 
{
public:
  double (*function)(double x);

  Base(double (*f)(double x));
};


}

#endif // #ifndef INTEGRAL_BASE_H
