//#include ...

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swp(int *arr)
{
    int swap;

    swap = arr[4];
    arr[4] = arr[7];
    arr[7] = swap;

    swap = arr[5];
    arr[5] = arr[6];
    arr[6] = swap;

    swap = arr[12];
    arr[12] = arr[14];
    arr[14] = swap;
}

int count_couple(int *arr)
{
    int count;

    swp(arr);

    for (int i = 0; i < 15; ++i) {
	for (int j = i; j < 15; ++j) {
	    if (arr[i] > arr[j]) {
		++count;
	    }
	}
    }

    swp(arr);

    return count;
}

int win_check(int *arr)
{
//  Вернуть 0, если пятнашки могут быть собраны
//  и 1, если нет
    if (count_couple(arr) % 2 == 1) {
	return 0;
    } else {
	return 1;
    }
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

//  Заполняем массив числами от 1 до 15 по порядку
    for (int i = 0; i < 15; ++i) {
	arr[i] = i + 1;
    }

//  Перемешиваем его случайные элементы случайное
//  количество раз, пока он не станет "собираемым"
    do {
	rand = getrand(20, 30);

	for (int i = 0; i < rand; ++i) {
	    swap1 = getrand(0, 15);
	    swap2 = getrand(0, 15);
	    save = arr[swap1];
	    arr[swap1] = arr[swap2];
	    arr[swap2] = save;
	}
    } while (win_check(arr));

    return *arr;
}