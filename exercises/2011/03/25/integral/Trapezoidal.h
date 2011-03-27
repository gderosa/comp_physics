// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_TRAPEZOIDAL_H
#define INTEGRAL_TRAPEZOIDAL_H


#include "Base.h"

namespace integral 
{

class Trapezoidal: public Base 
{
public:
  Trapezoidal(function::Base *f): Base(f) {} // inherit the constructor
  double compute();
};


}

#endif // #ifndef INTEGRAL_TRAPEZOIDAL_H
