#include <stdlib.h>

#ifndef MM_H
#define MM_H

double ** matrix_allocate(size_t n);

int matrix_free(double ** ptr, size_t n); 

#endif
