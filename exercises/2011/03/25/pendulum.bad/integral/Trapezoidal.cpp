// vim: set ts=2 sts=2 sw=2 et:

#ifdef DEBUG
#include <iostream>
#endif

#include "Trapezoidal.h"

namespace integral 
{

double Trapezoidal::compute()
{
  unsigned int i;
  double sum = 0;

  for(i=0; i<nIntervals(); i++) {
    sum += (
      (f[i] + f[i+1]) * deltaX() / 2.0
    );
  }

  return sum;
}

}
