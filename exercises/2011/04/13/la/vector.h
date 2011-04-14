#ifndef LA_VECTOR_H
#define LA_VECTOR_H

//#include <math.h>
#include <vector>

template<typename T>
std::vector<T> operator*(const T alpha, const std::vector<T> x)
{
  std::vector<T> y(x.size(), (T)0);
  size_t i;
  for (i=0; i<x.size(); i++) {
    y[i] = alpha * x[i];
  }
  return y;
}

template<typename T>
std::vector<T> operator*(const std::vector<T> x, const T alpha)
{
  return alpha*x;
}

namespace la
{
namespace vector
{

template<typename T, size_t N>
std::vector<T> diff(const std::vector<T> a, const std::vector<T> b)
{
  std::vector<T> c(N, (T)0);
  size_t i;
  for (i=0; i<N; i++) {
    c[i] = a[i] - b[i];
  }
  return c;
}

template<typename T, size_t N>
T squareNorm(const std::vector<T> x)
{
  T sum = (T)0;
  size_t i;
  for (i=0; i<N; i++) {
    sum += x[i]*x[i];
  }
  return sum;
}

template<typename T, size_t N>
T squareDistance(std::vector<T> a, std::vector<T> b)
{
  return squareNorm<T, N>(diff<T, N>(a, b)); 
}


} // namespace
} // namespace

#endif 
