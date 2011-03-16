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

int main() {
	Matrix A;	
	tridiag_simmetric_positive_init(A);
	matrix_print(A);
}
