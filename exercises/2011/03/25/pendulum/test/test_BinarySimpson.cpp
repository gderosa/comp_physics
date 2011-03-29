// vim: set ts=2 sts=2 sw=2 et:

#include <cmath>
#include <iomanip>
#include <iostream>

#include "../function/Base.h"
#include "../integral/BinarySimpson.h"

using namespace std;

struct Integrand : public function::Base
{
  double operator()(const double x) 
  {
    return cos(x);
  }
};

int main()
{
  Integrand f;
  integral::BinarySimpson binIntgr(&f, 0.0, M_PI/2.0, 1, 21);

  cout << setprecision(22);

  while (binIntgr.order < binIntgr.maxOrder) { 
    cout << binIntgr.compute() << ' ' << binIntgr.order << endl; 
    binIntgr.refineDiscretization();
  }
  cout << binIntgr.compute() << ' ' << binIntgr.order << endl;
  return 0;
}

