#ifndef DISCRETE_UNIFORM_FUNCTION_H
#define DISCRETE_UNIFORM_FUNCTION_H

#include <functional>

#include "Variable.h"

namespace discrete 
{
namespace uniform
{

struct Function : public std::unary_function<double, double>
{
  Variable        discreteVariable;

  void            setLowerEnd(  double        lowerEnd_   );
  void            setUpperEnd(  double        upperEnd_   );
  void            setNIntervals(unsigned int  nIntervals_ );

  virtual double  operator()(double x_      ); 
  double          operator[](unsigned int i ); 
};

}
}

#endif
