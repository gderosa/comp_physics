/* 
 * By Guido De Rosa, 2011, released to the Public Domain.
 *
 * Computational Physics course, Univ. of Naples
 *
 */

#include <stdio.h>
#include "splines_cholesky.h"

void matrix_print(Matrix A) {
	Index max_printable = 14;

	char * fmt = "%02.2f ";
	Index i, j;
	for (i=0; i<N; i++) {
		if (i < max_printable) {
			for (j=0; j<N; j++) {
				if (j < max_printable)
					printf(fmt, A[i][j]);
				else if (j == max_printable)
					printf("... ");
			}
			printf("\n"); 
		} else if (i == max_printable) 
			printf("... \n");
		else
			break;
	}
}


