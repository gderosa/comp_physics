// vim: set ts=2 sts=2 sw=2 et:

#ifndef INTERPOLATOR_BASE_H
#define INTERPOLATOR_BASE_H

#include <vector>

namespace interpolator
{


class Base 
{
public:
  double x(unsigned int i);
  double y(unsigned int i);

  Base(std::vector< std::pair<double, double> > points_);
protected:
  std::vector< std::pair<double, double> > points;
};


}

#endif // #ifndef INTERPOLATOR_BASE_H
