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

#include <stdio.h>
#include "cholesky.h"

int main() {
	Matrix A, L;	
	
	tridiag_simmetric_positive_init(A);

	cholesky_L(L, A);
	
	printf("A = \n");
	matrix_print(A);

	printf("\nL = \n");
	matrix_print(L);

	return 0;
}
