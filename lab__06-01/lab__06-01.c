#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int main()
{
	int ** matrix, m, n;
	int rowIdx = 0;

	puts("Enter the number of rows and columns in a matrix:");
	scanf("%d %d", &m, &n);
	puts("");

	if (!(m && n))
	{
		fprintf(stderr, "\nThe number of rows and columns is not valid.");

		return 1;
	}

	matrix = (int **)mallocMatrix(m, n, sizeof(** matrix));

	scanIntMatrix(matrix, m, n);
	puts("\nThe original matrix:");
	printIntMatrix(matrix, m, n);
	puts("\nEnter the index of the row that the matrix should be filtered by:");
	scanf("%d", &rowIdx);

	if (rowIdx < 0 || rowIdx > m - 1)
	{
		fprintf(stderr, "\nThe row index is not valid.");

		return 1;
	}

	sortIntMatrixColsByRow(matrix, rowIdx, m, n);
	puts("\nThe filtered matrix:");
	printIntMatrix(matrix, m, n);

	free(matrix);

	return 0;
}