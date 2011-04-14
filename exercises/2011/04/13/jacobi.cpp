#include <iostream>

#include "la/matrix/Square.h"
#include "la/matrix/JacobiWorkspace.h"

using namespace std;

int main(){
  la::matrix::Square<double, 3> A(
      1.1, 2.1, 3.1,
      2.1, 2.2, 3.2,
      3.1, 3.2, 3.3
  );
  la::matrix::JacobiWorkspace<double, 3> jacobi(A);
  size_t n;
  for (n=0; n<4; n++) {
    jacobi.rotate(0, 1);
    jacobi.rotate(0, 2);
    jacobi.rotate(1, 2);
  }
  cout << jacobi.Matrix << endl;
  cout <<  endl;
  cout << jacobi.AllRotations << endl;
}
