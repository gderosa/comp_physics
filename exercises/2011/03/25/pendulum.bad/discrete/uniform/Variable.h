#ifndef DISCRETE_UNIFORM_VARIABLE_H
#define DISCRETE_UNIFORM_VARIABLE_H

namespace discrete 
{
namespace uniform
{

struct Variable
{
  double        lowerEnd;
  double        upperEnd;
  unsigned int  nIntervals;

  Variable() {}
  Variable(double lowerEnd_, double upperEnd_, unsigned int nIntervals_);

  double stepWidth();
  double operator[](unsigned int i);
};

}
}

#endif
