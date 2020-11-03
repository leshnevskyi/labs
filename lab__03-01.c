#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DEFAULT_ARR_SIZE 4

void initIntArrWithNum(int *arr, int arrLen, int num);

int main()
{
	int minOne = INT_MAX, minTwo = INT_MAX;
	int *vector = malloc(DEFAULT_ARR_SIZE * sizeof(int));
	int *temp = NULL;
	int vectorLen = DEFAULT_ARR_SIZE;

	vector = malloc(DEFAULT_ARR_SIZE * sizeof(int));

	if (vector == NULL) exit(1);

	puts("Enter a number of elements in the array:");
	scanf("%d", &vectorLen);

	if (vectorLen > DEFAULT_ARR_SIZE)
	{
		int *temp = realloc(vector, vectorLen * sizeof(int));

		if (temp == NULL) exit(1);

		vector = temp;
	}

	for (int i = 0; i < vectorLen; ++i)
	{
		printf("Enter the %d value: ", i + 1);
		scanf("%d", &vector[i]);
	}

	if (!vectorLen)
	{
		puts("\nThere is no minimal number.");

		return 0;
	}

	if (vectorLen == 1)
	{
		printf("\nMinimal number = %d \n", *vector);

		return 0;
	}

	for (int i = 0; i < vectorLen; ++i)
	{
		int currEl = vector[i];

		if (currEl < minOne)
		{
			minTwo = minOne;
			minOne = currEl;
		}
		else if (currEl < minTwo)
		{
			minTwo = currEl;
		}
	}

	minOne == minTwo
		? printf("\nTwo minimal numbers = %d \n", minOne)
		: printf("\nAverage of two minimal numbers = %f \n", (minOne + minTwo) / 2.0);

	return 0;
}