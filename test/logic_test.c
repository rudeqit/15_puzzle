#include <ctest.h>
#include <logic.h>

CTEST(check_solvency, correct_win_combination)
{
	int arr[15];

	for (int i = 0; i < 16; ++i) {
		arr[i] = i + 1;
	}
	
	arr[15] = 0;

	const int result = check_solvency(arr);

	ASSERT_TRUE(result);
}

CTEST(check_solvency, correct_combination)
{
	int arr[] = {14, 5, 2, 3, 7, 12, 15, 11, 4,
		13, 9, 10, 1, 8, 6, 0};

	const int result = check_solvency(arr);

	ASSERT_TRUE(result);
}

CTEST(check_solvency, uncorrect_combination)
{
	int arr[15];

	for (int i = 0; i < 13; ++i) {
		arr[i] = i + 1;
	}
	
	arr[15] = 0;
	arr[14] = 14;
	arr[13] = 15;

	const int result = check_solvency(arr);

	ASSERT_FALSE(result);
}
