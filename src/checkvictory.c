//#include...

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