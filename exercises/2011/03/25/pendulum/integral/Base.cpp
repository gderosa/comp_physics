#include "Base.h"

namespace integral
{

Base::Base(discrete::uniform::Function f_) 
{
  f = f_;
}

double Base::deltaX() 
{ 
  return f.discreteVariable.stepWidth(); 
}

unsigned int Base::nIntervals() 
{ 
  return f.discreteVariable.nIntervals; 
}

double Base::lowerEnd()
{
  return f.discreteVariable.lowerEnd;
}

double Base::upperEnd()
{
  return f.discreteVariable.upperEnd;
}

double Base::compute()
{
  return 0.0;
}

void Base::setLowerEnd(double lowerEnd_)
{
  f.setLowerEnd(lowerEnd_);
}

void Base::setUpperEnd(double upperEnd_)
{
  f.setUpperEnd(upperEnd_);
}

void Base::setNIntervals(unsigned int nIntervals_)
{
  f.setNIntervals(nIntervals_);
}

} // namespace integral


