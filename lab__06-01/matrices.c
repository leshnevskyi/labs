#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void ** mallocMatrix(int m, int n, size_t typeSize)
{
	void ** matrix = NULL;

	matrix = malloc(m * sizeof(* matrix));

	if (matrix == NULL)
	{
		perror("Memory has not been allocated.");
		exit(1);
	}

	for (int i = 0; i < m; i++)
	{
		matrix[i] = malloc(m * typeSize);

		if (matrix[i] == NULL)
		{
			perror("Memory has not been allocated.");
			exit(1);
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
			scanf("%d", *(matrix + i) + j);
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

void swapIntMatrixCols(int ** matrix, int rowCount, int aIdx, int bIdx)
{
	for (int i = 0; i < rowCount; i++)
	{
		swapInt(&matrix[i][aIdx], &matrix[i][bIdx]);
	}
}

void sortIntMatrixColsByRow(int ** matrix, int rowIdx, int m, int n)
{
	int * row = matrix[rowIdx];
	int minIdx;

	for (int i = 0; i < n - 1; i++)
	{
		minIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (row[j] < row[minIdx])
			{
				minIdx = j;
			}
		}

		swapIntMatrixCols(matrix, m, minIdx, i);
	}
}