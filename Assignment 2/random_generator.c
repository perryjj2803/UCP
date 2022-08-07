#include <stdio.h>
#include <time.h>
#include "random_generator.h"

void initRandom()
{
	srand(time(NULL));
}

int Random(int low, int high)
{
	int number = -1;

	if(low <= high)
	{
		number = (rand() % (high-low+1)) + low;
	}

	return number;
}