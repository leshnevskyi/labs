#include <stdio.h>
#include "matrices.h"

int main()
{
	int ** matrix;
	int m, n;
	int sum, colIdx;
	int inputN;

	puts("Enter the number of rows: ");
	inputN = scanf("%d", &m);

	puts("Enter the number of columns: ");
	inputN = scanf("%d", &n);

	matrix = (int **)mallocMatrix(m, n, sizeof(* matrix));
	
	scanIntMatrix(matrix, m, n);

	puts("Enter the index of the column to reduce: ");
	inputN = scanf("%d", &colIdx);

	sum = getSumOfMatrixCol(matrix, m, colIdx);

	printf("The sum of elements of %d column = %d", colIdx + 1, sum);

	return 0;
}