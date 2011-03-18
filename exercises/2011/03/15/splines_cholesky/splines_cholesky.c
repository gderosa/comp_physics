#include <stdio.h>

#include "mm.h"
#include "splines_cholesky.h"
#include "random.h"

void intervals_generate(Intervals h) {
	Index i;
	for (i=0; i<NINTERVALS; i++) 
		h[i] = random_double(2.5);
}

/* see: T.Pang, Computational Ph., eq. 2.51 */
/* Here, matrix indices are lowered by 1 (they start from 0) */
void tridiag_simmetric_positive_init(Matrix A) {
	Index i, j;
	Intervals h = malloc(NINTERVALS * sizeof(double));

	intervals_generate(h);
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (i == j)
				A[i][i] = 2 * (h[i] + h[i+1]); 
			else if (i == j + 1) 
				A[i][j] = h[i];
			else if (j == i + 1)
				A[i][j] = h[j];
			else
				A[i][j] = 0.0;
		}
	}

	/* free(h); */
}

/* Algorithm should never make you read uninitialized values; otherwise
 * you would probably crash your program.
 */

void cholesky_L_diag(Matrix L, Matrix A, Index i) {
	double sum = 0.0;
	Index k;

	for (k=0; k<i; k++) 
		sum += L[i][k] * L[i][k];

	L[i][i] = sqrt(A[i][i] - sum);
}

void cholesky_L_other(Matrix L, Matrix A, Index i, Index j) {
	double sum = 0.0;
	Index k;

	for (k=0; k<j; k++)
		sum += L[j][k] * L[i][k]; 

	L[i][j] = (1 / L[j][j]) * (A[j][i] - sum); 
}

void cholesky_L(Matrix L, Matrix A) {
	Index i, j;

	for (i=0; i<N; i++) {
		printf("Computing row #%d out of %d \t \r", i, N);
		for (j=0; j<N; j++) {
			if ( i < j )
				L[i][j] = 0.0;
			else if ( i == j ) 
				cholesky_L_diag(L, A, i);
			else
				cholesky_L_other(L, A, i, j);	
		}
	}
}
