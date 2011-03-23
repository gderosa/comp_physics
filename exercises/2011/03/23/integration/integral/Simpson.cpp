// vim: set ts=2 sts=2 sw=2 et:

#ifdef DEBUG
#include <iostream>
#endif

#include "Simpson.h"

namespace integral 
{

// Assume there's an even number of intervals.
// TODO: handle the odd case.
double Simpson::compute()
{
  unsigned int j;
  double sum = 0;

  for(j = 0; j < (nIntervals/2); j++) {
    sum += (
          f(2*j)      + 
      4 * f(2*j + 1)  +
          f(2*j + 2)
    );
  }

  return sum;
}

}
