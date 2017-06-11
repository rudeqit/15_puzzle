#include <ctest.h>
#include <logic.h>

CTEST(check_solvency, correct_win_combination)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 0};

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
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 15, 14, 0};

	const int result = check_solvency(arr);

	ASSERT_FALSE(result);
}
