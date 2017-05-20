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

void swapvalues(int* arr, int x, int y)
{
	int sv;
	sv = arr[x];
	arr[x] = arr[y];
	arr[y] = sv;
}

int search_zero(int* arr)
{
	int zero_pos = 0;

	while (arr[zero_pos] != 0) {
		zero_pos++;
	}

	return zero_pos;
}
void randomize_board(int* arr)
{
	srand(time(NULL));
	int c, j, a, b;
	int i = rand()%(71) + 30;

	for (j = 1; j < i; j++) {
		a = rand()%(16) + 0;
		b = rand()%(16) + 0;
		c = arr[a];
		arr[a] = arr[b];
		arr[b] = c;
	}
}

/*
int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
*/

/*
int* get_new_numbers()
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

    return arr;
}
*/

/*
int count_couple(int *arr)
{
    int count;
    int mas[] = {arr[0], arr[1], arr[2], arr[3], arr[7], arr[6], arr[5],
	arr[4], arr[8], arr[9], arr[10], arr[11], arr[14], arr[13], arr[12]};

    for (int i = 0; i < 15; ++i) {
	for (int j = i; j < 15; ++j) {
	    if (mas[i] > mas[j]) {
		++count;
	    }
	}
    }

    return count;
}
*/

/*
int check_victory(int *arr)
{
//  Вернуть 0, если пятнашки могут быть собраны
//  и 1, если нет
    if (count_couple(arr) % 2 == 1) {
	return 0;
    } else {
	return 1;
    }
}
*/

/*
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
*/
