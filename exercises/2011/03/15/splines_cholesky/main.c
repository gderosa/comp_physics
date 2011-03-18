/* 
 * By Guido De Rosa, 2011, released to the Public Domain.
 *
 * Computational Physics course, Univ. of Naples
 *
 * Cholesky decomposition.
 *
 */

#include "mm.h"
#include "splines_cholesky.h"
#include "random.h"
#include "io.h"

int main() {
	Matrix A = matrix_allocate(N);
	Matrix L = matrix_allocate(N);

	random_init();	
	
	tridiag_simmetric_positive_init(A);

	cholesky_L(L, A);
	
	printf("\nA = \n"); 
	matrix_print(A);

	printf("\nL = \n"); 
	matrix_print(L);

	matrix_free(A, N);
	matrix_free(L, N);

	return 0;
}
