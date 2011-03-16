/* 
 * Cholesky decomposition.
 *
 * Ref. Numerical Recipes, 3rd Ed., Sec 2.9 (Math only) 
 *
 */

#include "cholesky.h"

/* A matrix with all diagonal elements = 1 and A[i][j] = 0.5 
 * when |i - j| = -1 happens to be positive definite.
 */

void diag_positive_init(Diagonal diag) {
	Index i;
	for (i=0; i<N; i++) 
		diag[i] = 1.0;
}

void subdiag_positive_init(Subdiagonal subdiag) {
	Index i;
	for (i = 0; i < N-1; i++)
		subdiag[i] = 0.5;
}

void tridiag_simmetric_positive_init(Matrix A) {
	Index i, j;
	Diagonal diag;
	Subdiagonal subdiag;

	diag_positive_init(diag);
	subdiag_positive_init(subdiag);
	
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (i == j)
				A[i][i] = diag[i];
			else if (i == j + 1) 
				A[i][j] = subdiag[j];
			else if (j == i + 1)
				A[i][j] = subdiag[i];
			else
				A[i][j] = 0.0;
		}
	}
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
