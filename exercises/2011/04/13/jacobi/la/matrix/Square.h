#ifndef LA_MATRIX_SQUARE_H
#define LA_MATRIX_SQUARE_H

#include <cstdarg>
#include <vector>

//TODO: move this I/O stuff elsewhere
#include <ostream>
#include <iomanip>

namespace la
{
namespace matrix
{

template <typename T, size_t N>
class Square   
{
public:  
  Square() 
  {
    data.resize(N);
    size_t i;
    for (i=0; i<N; i++) {
      std::vector<T> row(N, (T)0); 
      data[i] = row;
    }
  }
  Square(T element_00, ...)  
  {
    data.resize(N);
    size_t i,j;
    for (i=0; i<N; i++)
      data[i].resize(N);
    va_list ap;
    va_start(ap, element_00);
    // put the first element
    data[0][0] = element_00;
    // put the other elements of first row
    for (j=1; j<N; j++) {
      data[0][j] = va_arg(ap, T);
    }
    // fill the other rows
    for (i=1; i<N; i++) {
      for (j=0; j<N; j++) {
        data[i][j] = va_arg(ap, T);
      }
    }
    va_end(ap);
  }

  std::vector<T> & operator[](const size_t i)
  {
    return data[i];
  }

  Square<T, N> transposed()
  {
    Square<T, N> Transposed;
    size_t i, j;
    for (i=0; i<N; i++) {
      for (j=0; j<N; j++) {
        Transposed[i][j] = (*this)[j][i];
      }
    }
    return Transposed;
  }

  std::vector<T> column(size_t j)
  {
    std::vector<T> col(N, (T)0);
    size_t i;
    for (i=0; i<N; i++) {
      col[i] = (*this)[i][j];
    }
    return col;
  }

  std::vector<T> row(size_t i)
  {
    return (*this)[i];
  }
  
  size_t size()
  {
    return N;
  }

  static Square<T, N> identity()
  {
    Square<T, N> I;
    size_t i;
    for (i=0; i<N; i++)
      I[i][i] = (T)1;
    return I;
  }

private:
  std::vector< std::vector<T> > data;
};

// matrix operations
template <typename T, size_t N>
Square<T, N> operator*(Square<T, N> & A, Square<T, N> & B) 
  // const correctness is not possible here
{
  Square<T, N> Result;
  size_t i, j, k;
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      for (k=0; k<N; k++) {
        Result[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return Result;
}

template <typename T, size_t N>
std::vector<T> operator*(Square<T, N> & A, std::vector<T> & x)
{
  std::vector<T> y(N, (T)0);
  size_t i, j;
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
  return y;
}

}
}




// I/O stuff : TODO: move to a separate file

template<typename T, size_t N>
std::ostream& operator<<(std::ostream& cout, la::matrix::Square<T, N> A)
{
  size_t i, j;
  for (i=0; i<N; i++) {  
    for (j=0; j<N; j++) {
      cout << std::setw(14) << A[i][j];
    }
    cout << std::endl;
  }
  return cout;
}

#endif 
