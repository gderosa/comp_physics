/* 
 * By Guido De Rosa, 2011, released to the Public Domain.
 *
 * Computational Physics course, Univ. of Naples
 *
 * Cholesky decomposition.
 *
 * Ref. Numerical Recipes, 3rd Ed., Sec 2.9 (Math only) 
 *
 */

/* Resources for matrices and vectors are statically allocated here */
/* TODO: use malloc() etc. */

#include <math.h>

#define N 10

typedef double Matrix[N][N];
typedef double Diagonal[N];
typedef double Subdiagonal[N-1];
typedef unsigned int Index;

void diag_positive_init(Diagonal diag);

void subdiag_positive_init(Subdiagonal subdiag); 

void tridiag_simmetric_positive_init(Matrix A);

void cholesky_diag(Matrix L, Index i);
void cholesky_other(Matrix L, Index i, Index j);
void cholesky_lower(Matrix L, Matrix A);

void matrix_print(Matrix A);

