#include "Function.h"

namespace discrete
{
namespace uniform
{

void Function::setLowerEnd(double lowerEnd_)
{
  discreteVariable.lowerEnd = lowerEnd_;
}

void Function::setUpperEnd(double upperEnd_)
{
  discreteVariable.upperEnd = upperEnd_;
}

void Function::setNIntervals(unsigned int nIntervals_)
{
  discreteVariable.nIntervals = nIntervals_;
}

double Function::operator()(double x_)
{
  return 0.0;
}

double Function::operator[](unsigned int i)
{
  return operator()(discreteVariable[i]); 
}

}
}
