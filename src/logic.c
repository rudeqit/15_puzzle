#include <string.h>
#include <stdlib.h>
#include <time.h>
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

void randomize_board(int* arr)
{
	srand(time(NULL));
	int c, j, a, b;
	int i = rand()%(71) + 30;
	for(j = 1; j < i; j++){
		a = rand()%(16) + 0;
		b = rand()%(16) + 0;
		c = arr[a];
		arr[a] = arr[b];
		arr[b] = c;
	}
}
