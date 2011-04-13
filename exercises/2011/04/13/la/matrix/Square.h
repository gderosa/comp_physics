#include <cstdarg>
#include <vector>
#include <ostream>

#include "../Vector.h"

namespace la
{
namespace matrix
{

template <typename T, size_t N>
class Square   
{
public:  
  std::vector< std::vector<T> > data;

  Square() 
  {
    data.resize(N);
    size_t i;
    for (i=0; i<N; i++) {
      std::vector<T> row(N, 0.0);
      data[i] = row;
    }
  }
  Square(double element_00, ...)  
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
      data[0][j] = va_arg(ap, double);
    }
    // fill the other rows
    for (i=1; i<N; i++) {
      for (j=0; j<N; j++) {
        data[i][j] = va_arg(ap, double);
      }
    }
    va_end(ap);
  }

  std::vector<T> operator[](const size_t i)
  {
    return data[i];
  }
private:
  size_t current_row;
};

}
}

// I/O stuff : TODO: move to a separate file


template<typename T, size_t N>
std::ostream& operator<<(std::ostream& cout, la::matrix::Square<T, N> A)
{
  size_t i, j;
  for (i=0; i<N; i++) {  
    for (j=0; j<N; j++) {
      cout << A[i][j] << ' ';
    }
    cout << std::endl;
  }
  return cout;
}
