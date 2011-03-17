/* 
 * By Guido De Rosa, 2011, released to the Public Domain.
 *
 * Computational Physics course, Univ. of Naples
 *
 * Cholesky decomposition.
 *
 */

#include <stdio.h>
#include "splines_cholesky.h"
#include "random.h"

int main() {
	Matrix A, L;

	random_init();	
	
	tridiag_simmetric_positive_init(A);

	cholesky_L(L, A);
	
	printf("A = \n");
	matrix_print(A);

	printf("\nL = \n");
	matrix_print(L);

	return 0;
}
