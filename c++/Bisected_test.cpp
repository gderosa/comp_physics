#include <iostream>
#include "Bisected.h"

struct MyFunc 
{
  double operator()(const double x) {return x;}
};

int main() {
  function::BisectMixin<MyFunc> f(0.0, 1.0, 1);
  f.refine();
  size_t i;
  std::list<double>::iterator it;
  for(it=f.values.begin(); it!=f.values.end(); it++) {
    std::cout << *it << std::endl;
  }
}
