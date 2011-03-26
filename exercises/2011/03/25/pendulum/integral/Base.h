// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTEGRAL_BASE_H
#define INTEGRAL_BASE_H

#include "../discrete/uniform/Function.h"

namespace integral 
{

class Base 
{
public:
  discrete::uniform::Function f;

  Base() {};
  Base(discrete::uniform::Function f_); 

  double        deltaX();
  double        lowerEnd();
  double        upperEnd();
  unsigned int  nIntervals(); 

  void setLowerEnd(   double        lowerEnd_   );
  void setUpperEnd(   double        upperEnd_   ); 
  void setNIntervals( unsigned int  nIntervals_ );

  virtual double compute();
};


}

#endif // #ifndef INTEGRAL_BASE_H
