#include "ctest.h"
#include "logic.h"

CTEST(check_solvency, correct_win_combination)
{
	int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 0};
	const int result = check_solvency(arr);
	const int expect = 0;

	ASSERT_EQUAL(expect, result);
}

CTEST(check_solvency, random_correct_combination)
{
	int arr[16] = {13, 3, 10, 4, 2, 14, 9, 1, 
		15, 6, 12, 5, 7, 11, 8, 0};
	const int result = check_solvency(arr);
	const int expect = 0;

	ASSERT_EQUAL(expect, result);
}

CTEST(check_solvency, random_uncorrect_combination)
{
	int arr[16] = {13, 3, 10, 4, 2, 6, 9, 1, 
		15, 14, 12, 5, 7, 11, 8, 0};
	const int result = check_solvency(arr);
	const int expect = 1;

	ASSERT_EQUAL(expect, result);
}

CTEST(check_solvency, uncorrect_15_14_combination)
{
	int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 15, 14, 0};

	const int result = check_solvency(arr);
	const int expect = 1;

	ASSERT_EQUAL(expect, result);
}

CTEST(check_victory, correct_win_combination)
{
	int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 0};
	const int result = check_victory(arr);
	const int expect = 1;

	ASSERT_EQUAL(expect, result);
}

CTEST(check_victory, uncorrect_win_combination)
{
	int arr[16] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 0};
	const int result = check_victory(arr);
	const int expect = 0;

	ASSERT_EQUAL(expect, result);
}
