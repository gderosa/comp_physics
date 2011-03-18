#include <stdlib.h>
#include <time.h>

#ifndef RANDOM_H
#define RANDOM_H

#define random_init() srand((unsigned)time(NULL))

#define random_double(MAX) \
	MAX * ( \
		( (double)rand() ) / (double)RAND_MAX \
	)

#endif 
