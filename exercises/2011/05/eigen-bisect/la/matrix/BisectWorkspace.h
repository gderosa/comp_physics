// Assumes tri-diagonal matrices

#ifndef LA_MATRIX_BISECT_WORKSPACE
#define LA_MATRIX_BISECT_WORKSPACE

#include <math.h>

#include "Square.h"

namespace la
{
namespace matrix
{

template<typename T, size_t N>
class BisectWorkspace
{
public:
  Square<T, N> Matrix;

  BisectWorkspace(Square<T, N> & A)
  {
    Matrix = A;
  }

  // Returns a vector P where P[k] is the carachteristic
  // polynomial of k-th minor. As usual you have to subtract 1
  // from indices found in "mathematical" formulae (where they start 
  // from 1, and 0 is only used with special meanings).
  std::vector<T> P(T lambda) 
  {
    Square & A = Matrix; // a shortcut
    std::vector<T> P_(N) ;
    size_t k;
    P_[0] = A[0][0] - lambda;
    if (N > 1) {
      P_[1] = (A[1][1] - lambda)*P_[0] - A[0][1]*A[0][1]; 
    }
    for (k=2; k<N; k++) {
      P_[k] = (A[k][k] - lambda)*P_[k-1] - A[k-1][k]*A[k-1][k]*P_[k-2];
    }
    return P_;
  }
};

}
}

#endif
