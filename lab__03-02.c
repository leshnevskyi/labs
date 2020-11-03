#include <stdio.h>

#define M 3
#define N 4

void scanMatrix(int matrix[M][N]);
void printMatrix(int matrix[M][N]);
void shiftMatrixRows(int matrix[M][N], int nShifts);

int main()
{
	int matrix[M][N] = {0};
	int nShifts = 1;

	scanMatrix(matrix);

	puts("Original matrix:\n");
	printMatrix(matrix);

	shiftMatrixRows(matrix, nShifts);

	printf("The same matrix with rows shifted by %d:\n", nShifts);
	printMatrix(matrix);

	return 0;
}

void scanMatrix(int matrix[M][N])
{
	for (int i = 0; i < M; ++i)
	{
		printf("Enter %d elements of %d row:\n", N, i + 1);

		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &matrix[i][j]);
		}

		puts("\n");
	}
}

void printMatrix(int matrix[M][N])
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}

		puts("\n");
	}
}

void shiftMatrixRows(int matrix[M][N], int nShifts)
{
	int lastRow[N];

	while (nShifts)
	{
		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == M - 1) lastRow[j] = matrix[i][j];

				if (!i)
				{
					matrix[i][j] = lastRow[j];
					continue;
				}

				matrix[i][j] = matrix[i - 1][j];
			}
		}

		nShifts--;
	}
}