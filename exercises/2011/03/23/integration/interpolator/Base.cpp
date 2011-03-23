// vim: set ts=2 sts=2 sw=2 et:

#include <vector>

#include "Base.h"

namespace interpolator
{


Base::Base(std::vector< std::pair<double, double> > &points_)
{
  points = points_; 
}

double Base::x(unsigned int i)
{
  return points[i].first;
}

double Base::y(unsigned int i)
{
  return points[i].second;
}


}
