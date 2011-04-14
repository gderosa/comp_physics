#include <iostream>

#include "la/matrix/Square.h"
#include "la/matrix/JacobiWorkspace.h"

using namespace std;

int main(){
  la::matrix::Square<double, 4> A(
      1.1,   2.1,   3.1,   4.0,
      2.1,   2.2,   3.2,   5.0,
      3.1,   3.2,   3.3,   2.4,
      4.0,   5.0,   2.4,  -1.0
  );
  la::matrix::JacobiWorkspace<double, 4> jacobi(A);
  size_t n = 0;
  size_t p, q;
  double norm = jacobi.offDiagonalNorm();
  cout << endl << "Initial off-diagonal norm = " << norm << endl;
  for (n=1; norm > 1e-100; n++) {
    for (q=0; q < A.size(); q++) {
      for (p=0; p<q; p++) {
        jacobi.rotate(p, q);
      }
    }
    norm = jacobi.offDiagonalNorm();
    cout << "iteration #" << n << " off-diagonal norm = " << norm << endl;
  }
  cout << endl;
  cout << "Diagonalized matrix:" << endl;
  cout << jacobi.Matrix << endl;
  cout << "Eigenvectors:" << endl;
  cout << jacobi.AllRotations << endl;
}
