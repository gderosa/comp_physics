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

#include "cholesky.h"

/* Having all elements > 0 is enough (but not necessary!) to guarantee
 * that the matrix is positive-definite.
 */

/* Quite stupid. Initialize with all 1's. 
 * TODO: use random numbers or other fancy things. 
 */
void diag_positive_init(Diagonal diag) {
	Index i;
	for (i=0; i<N; i++) 
		diag[i] = 1.0;
}

/* As stupid as diag_positive_init() */
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
	
	for	(i=0; i<N; i++) {
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

