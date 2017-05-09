#include "checkvictory.h"

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