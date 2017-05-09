//#include...

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