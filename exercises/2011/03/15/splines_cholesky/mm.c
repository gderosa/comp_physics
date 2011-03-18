#include <stdlib.h>

double ** matrix_allocate(size_t n) {
	size_t i, j;
	double ** ptr = malloc(n * sizeof(double *));

	for (i=0; i<n; i++) {
		ptr[i] = malloc(n * sizeof(double));
	}

	return ptr;
}

int matrix_free(double ** ptr, size_t n) {
	size_t i, j;

	if (ptr) {
		for (i=0; i<n; i++) {
			free(ptr[i]);
		}
		free(ptr);
		return 0;	
	}
	else
		return -1;	
}
