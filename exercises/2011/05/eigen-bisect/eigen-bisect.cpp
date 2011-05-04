#include <iostream>

#include "la/vector.h"
#include "la/matrix/Square.h"
#include "la/matrix/BisectWorkspace.h"

using namespace std;

int main(){
  la::matrix::Square<double, 4> A(
      1.1,   2.1,   0.0,   0.0,
      2.1,   2.2,   3.2,   0.0,
      0.0,   3.2,   3.3,   2.4,
      0.0,   0.0,   2.4,  -1.0
  );
  cout << "Input matrix A:" << endl << A;
  la::matrix::BisectWorkspace <double, 4> bisectWorkspace(A);
}





