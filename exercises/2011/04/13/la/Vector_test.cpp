#include <iostream>

#include "Vector.h"

using namespace std;

int main(){
  double init_a[] = {1.0, 1.0, 1.0};
  double init_b[] = {1.0, 1.0, -2.0};
  la::Vector<double> a(init_a, 3);
  la::Vector<double> b(init_b, 3);
  cout << a*b << endl;
}
