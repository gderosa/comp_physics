// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTERPOLATOR_POLYNOMIAL_H
#define INTERPOLATOR_POLYNOMIAL_H

#include "Base.h"

namespace interpolator 
{


class Polynomial: public Base 
{
public:
  Polynomial( // inherit the constructor
      std::vector< std::pair<double, double> > points ): Base(points) {} 
};


}

#endif 
