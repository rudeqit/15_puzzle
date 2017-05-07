//#include ...

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int get_new_numbers()
{
    int arr[15], swap1, swap2, save;
    int rand = getrand(20, 30);

    srand(time(NULL));

//  Сначала заполняем массив числами от 1 до 15
    for (int i = 0; i < 15; ++i) {
	arr[i] = i + 1;
    }

//  А затем перемешиваем его случайные элементы
//  случайное количество раз
    for (int i = 0; i < rand; ++i) {
	swap1 = getrand(0, 15);
	swap2 = getrand(0, 15);
	save = arr[swap1];
	arr[swap1] = arr[swap2];
	arr[swap2] = save;
    }

    return *arr;
}

/*

int main()
{
    int arr[];
    int *arr = get_new_numbers();

    for () {

    }

    for (int i = 0; i < 15; ++i) {
	printf("%d ", arr[i]);
    }

    return 0;
}

*/