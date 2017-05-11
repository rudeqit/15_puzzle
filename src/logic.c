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

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int get_new_numbers()
{
    int arr[15], swap1, swap2, save;
    int rand;

    srand(time(NULL));

    for (int i = 0; i < 15; ++i) {
	arr[i] = i + 1;
    }

    do {
	rand = getrand(20, 30);

	for (int i = 0; i < rand; ++i) {
	    swap1 = getrand(0, 15);
	    swap2 = getrand(0, 15);
	    save = arr[swap1];
	    arr[swap1] = arr[swap2];
	    arr[swap2] = save;
	}
    } while (check_victory(arr));

    return *arr;
}

int endgame(int *arr) 
{
    for (int i = 0; i < 15; ++i) {
	if (arr[i] != i + 1) {
	    return 0;
	    break;
	}
    }

    return 1;
}
