//#include ...

int count_couple(int *arr)
{
    int count, swap;

    swap = arr[4];
    arr[4] = arr[7];
    arr[7] = swap;

    swap = arr[5];
    arr[5] = arr[6];
    arr[6] = swap;

    swap = arr[12];
    arr[12] = arr[14];
    arr[14] = swap;

    for (int i = 0; i < 15; ++i) {
	for (int j = i; j < 15; ++j) {
	    if (arr[i] > arr[j]) {
		++count;
	    }
	}
    }

    return count;
}

int win_check(int *arr)
{
    if (count_couple(arr) % 2 == 1) {
	return 1;
    } else {
	return 0;
    }
}