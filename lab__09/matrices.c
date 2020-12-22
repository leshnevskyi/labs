#include <stdio.h>
#include <stdlib.h>

int inputN;

void ** mallocMatrix(int m, int n, size_t size)
{
	void ** matrix = NULL;

	matrix = (void **)malloc(m * sizeof(* matrix));

	if (matrix == NULL)
	{
		perror("Memory has not been allocated.");

		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < m; i++)
	{
		matrix[i] = malloc(m * size);

		if (matrix[i] == NULL)
		{
			perror("Memory has not been allocated.");

			exit(EXIT_FAILURE);
		}
	}

	return matrix;
}

void scanIntMatrix(int ** matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		printf(
			"Enter %d elements of the %d row: \n",
			n, i + 1
		);

		for (int j = 0; j < n; j++)
		{
			inputN = scanf("%d", *(matrix + i) + j);
		}
	}
}

void printIntMatrix(int ** matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d ", matrix[i][j]);
		}

		puts("");
	}
}

int getSumOfMatrixCol(int ** matrix, int m, int colIdx)
{
	int sum = 0;

	for (int i = 0; i < m; i++)
	{
		sum += matrix[i][colIdx];
	}

	return sum;
}