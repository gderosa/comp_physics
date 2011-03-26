#include "Variable.h"

namespace discrete
{
namespace uniform
{

Variable::Variable(double lowerEnd_, double upperEnd_, unsigned int nIntervals_)
{
  lowerEnd    = lowerEnd_;
  upperEnd    = upperEnd_;
  nIntervals  = nIntervals_;
}

double Variable::stepWidth()
{
  return (upperEnd - lowerEnd) / (double)nIntervals;
}

double Variable::operator[](unsigned int i)
{
  return lowerEnd + i*stepWidth();
}

}
}
