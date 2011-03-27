#ifndef FUNCTION_BASE_H
#define FUNCTION_BASE_H

namespace function
{

struct Base
{
  virtual double operator()(double x) {return 0.0;}
};

}

#endif // FUNCTION_BASE_H
