#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "getnewnumbers.h"

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