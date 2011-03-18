/* 
 * By Guido De Rosa, 2011, released to the Public Domain.
 *
 * Computational Physics course, Univ. of Naples
 *
 */

#include "io.h"

void matrix_print(Matrix A) {
	char * fmt = "%02.2f ";
	Index i, j;

	for (i=0; i<N; i++) {
		if (i < MAX_PRINTABLE_ROWS) {
			for (j=0; j<N; j++) {
				if (j < MAX_PRINTABLE_COLS)
					printf(fmt, A[i][j]);
				else if (j == MAX_PRINTABLE_COLS)
					printf("... ");
			}
			printf("\n"); 
		} else if (i == MAX_PRINTABLE_ROWS) 
			printf("... \n");
		else
			break;
	}
}


