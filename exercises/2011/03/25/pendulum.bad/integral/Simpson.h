// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_SIMPSON_H
#define INTEGRAL_SIMPSON_H


#include "Base.h"

namespace integral 
{

class Simpson: public Base 
{
public:
  // inherit the constructor
  Simpson(discrete::uniform::Function f): Base(f) {}
  double compute();
};


}

#endif // #ifndef INTEGRAL_TRAPEZOIDAL_H
