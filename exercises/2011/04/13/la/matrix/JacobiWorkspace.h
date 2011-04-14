// See Numerical Recipes, 3rd Ed., Sec. 11.1 (math only)

#ifndef LA_MATRIX_JACOBI_WORKSPACE
#define LA_MATRIX_JACOBI_WORKSPACE

#include <math.h>

#include "Square.h"

namespace la
{
namespace matrix
{

template<typename T, size_t N>
class JacobiWorkspace
{
public:
  Square<T, N> AllRotations;
  Square<T, N> Matrix;

  JacobiWorkspace(Square<T, N> & A)
  {
    Matrix = A;
    AllRotations = Square<T, N>::identity();
  }

  T offDiagonalNorm()
  {
    T sum = (T)0;
    size_t i , j;
    for (i=0; i<N; i++) {
      for (j=0;   j<i; j++) sum += fabs(Matrix[i][j]) * fabs(Matrix[i][j]);
      for (j=i+1; j<N; j++) sum += fabs(Matrix[i][j]) * fabs(Matrix[i][j]);
    }
    return sum;
  }

  void rotate(const size_t p, const size_t q) // assuming p < q
  {
    // This will *not* work with complex. TODO: specialized templates
    Square<T, N> Rotation = Square<T, N>::identity();
    Square<T, N> Old = Matrix;
    T s, c, t, theta;
    theta = (Matrix[p][p] - Matrix[q][q]) / (2 * Matrix[p][q]) ;
    if ( fabs(theta) < 1e100 )
      t = (theta/fabs(theta)) / (fabs(theta) + sqrt(theta*theta + 1)) ; 
    else // avoid overflows
      t = 1 / (2*theta);
    c = 1.0 / sqrt(t*t + 1.0);
    s = t * c;
    Rotation[p][p] = c;
    Rotation[q][q] = c;
    Rotation[p][q] = s;
    Rotation[q][p] = -s;
    AllRotations = AllRotations * Rotation;
    // direct calculation, see Eq. 11.1.14+
    T tau = s / (1.0 + c);
    size_t r;
    for(r=0; r<N; r++) {
      if ((r != p) && (r != q)) { 
        Matrix[r][p] = Matrix[p][r] = Old[r][p] - s*(Old[r][q] - tau*Old[r][p]);
        Matrix[r][q] = Matrix[q][r] = Old[r][q] + s*(Old[r][p] + tau*Old[r][q]);
      }
    }
    Matrix[p][p] = Old[p][p] - t*Old[p][q];
    Matrix[q][q] = Old[q][q] + t*Old[p][q];
    Matrix[p][q] = Matrix[q][p] = 0.0; 
  }
};

}
}

#endif
