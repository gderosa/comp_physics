/* 
 * By Guido De Rosa, 2011, released to the Public Domain.
 *
 * Computational Physics course, Univ. of Naples
 *
 * Cholesky decomposition of the matrix got from a splines 
 * interpolation problem (fixed number of points).
 *
 * See:
 * * Numerical Recipes, 3rd Ed., Sec 2.9  
 * * T. Pang, Indtroduction to Computational Physics, 2nd Ed., sec. 2.4
 *
 */

#include <math.h>

#define NPOINTS 12
#define NINTERVALS (NPOINTS - 1)
#define N (NINTERVALS - 1) 

typedef double Intervals[NINTERVALS];
typedef double Matrix[N][N];
typedef double Vector[N];
typedef unsigned int Index;

void intervals_generate(Intervals h);

void tridiag_simmetric_positive_init(Matrix A);

void cholesky_diag(Matrix L, Matrix A, Index i);
void cholesky_other(Matrix L, Matrix A, Index i, Index j);
void cholesky_lower(Matrix L, Matrix A);

void matrix_print(Matrix A);

