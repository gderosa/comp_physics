#include <vector>

namespace la
{

template <typename T>
class Vector : public std::vector<T>
{
public:
  Vector(const T * carray, const size_t size) : 
      std::vector<T>::vector(
          carray, 
          carray + size*sizeof(T)
      )
  {} 

  T operator*(const Vector & other) // scalar product
  {
    T sum = (T)0;
    size_t i;
    for (i=0; i < this->size(); i++) {
      sum += ( this->at(i) * other[i] ) ; 
    }
    return sum;
  }
};

}
