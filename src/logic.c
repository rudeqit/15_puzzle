#include <string.h>
#include <stdlib.h>
#include "logic.h"

int* create_array(size_t size)
{
	int* result = malloc(sizeof(int) * size);
	memset(result, 0, sizeof(int) * size);
	return result;
}

int* filling_array()
{
	size_t size = 16;

	int* arr = create_array(size);

	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}

	return arr;
}


