#include "logic.h"

int* create_array(int size)
{
	int* result = malloc(sizeof(int) * size);
	memset(result, 0, sizeof(int) * size);

	return result;
}

int* filling_array()
{
	size_t size = 16;

	int* arr = create_array(size);

	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}

	randomize_board(arr);

	return arr;
}

void randomize_board(int* arr)
{
	srand(time(NULL));
	int c, j, a, b;
	int i = rand() % (71) + 30;

	do {
		for (j = 1; j < i; ++j) {
			a = rand() % (16) + 0;
			b = rand() % (16) + 0;
			c = arr[a];
			arr[a] = arr[b];
			arr[b] = c;
		}
		if (arr[15]) {
			int zer = find_zero_pos(arr);
			swapvalues(arr, zer, 15);
		}
	} while (count_couple(arr) == 1); 
}

int find_zero_pos(int* arr)
{
	int i = 0; 

	while (arr[i] != 0) {
		i++;
	}

	return i;
}

void swapvalues(int* arr, int x, int y)
{
	int sv;
	sv = arr[x];
	arr[x] = arr[y];
	arr[y] = sv;
}

int mask_build(int* arr, int* mask)
{
	int zero_pos = find_zero_pos(arr);

	if (zero_pos < 4) {
		mask[2] = 0;
	} else {
		mask[2] = 1;
	} 

	if (zero_pos > 11) {
		mask[1] = 0;
	} else {
		mask[1] = 1;
	} 
	
	if (zero_pos != 0 && (zero_pos + 1) % 4 == 0) {
		mask[3] = 0;
	} else {
		mask[3] = 1;
	} 
	
	if (zero_pos == 0 || zero_pos % 4 == 0) {
		mask[0] = 0;
	} else {
		mask[0] = 1;
	}
 
	return zero_pos;
}

int check_board(int* arr)
{
	for (int i = 0; i < 16; i++) {
		if (i != 15 && arr[i] != i + 1) {
			return 0;
		} else if (i == 15 && arr[i]) {
			return 0;
		}
	}

	return 1;
}

int count_couple(int *arr)
{
	int count, zero_line;

	for (int i = 0; i < 16; ++i) {
		if (!arr[i]) {
			zero_line = i / 4 + 1;
		}
		for (int j = i; j < 16; ++j) {
			if (arr[i] > arr[j] && arr[j]) {
				++count;
			}
		}
	}

	count += zero_line;
	
	return count;
}

int check_victory(int *arr)
{
    if (count_couple(arr) % 2 == 0) {
		return 0;
    } else {
		return 1;
    }
}
