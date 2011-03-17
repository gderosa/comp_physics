#include <stdlib.h>
#include <time.h>

#define random_init() srand((unsigned)time(NULL))

#define random_double(MAX) \
	MAX * ( \
		( (double)rand() ) / (double)RAND_MAX \
	)

