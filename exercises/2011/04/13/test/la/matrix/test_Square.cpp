#include <iostream>

#include "../../../la/matrix/Square.h"

using namespace std;

int main(){
  la::matrix::Square<double, 3> A(
      1.1, 1.2, 1.3,
      2.1, 2.2, 2.3,
      3.1, 3.2, 3.3
  );
  la::matrix::Square<double, 3> B(
      1.0, 0.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 0.0, 1.0
  );
  cout << A * B << endl;
}
