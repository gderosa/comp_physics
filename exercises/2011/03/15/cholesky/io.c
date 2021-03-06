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

void matrix_print(Matrix A) {
	char * fmt = "%02.2f ";
	Index i, j;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf(fmt, A[i][j]);
		}
		printf("\n"); 
	}
}


