#include <stdio.h>
#include <stdlib.h>

int decimalToOctal(int x);
int * getPrimeNums(int min, int max, int * count);
void printPrimeNumsInOctal(int min, int max);

int main()
{
	int min, max;

	printf("Set the boundaries: \n");
	scanf("%d %d", &min, &max);

	printPrimeNumsInOctal(min, max);

	return 0;
}

int decimalToOctal(int x)
{
	return !x
		? 0
		: x % 8 + 10 * decimalToOctal(x / 8);
}

int * getPrimeNums(int min, int max, int * count)
{
	int len;
	int * arr;
	int isPrime;
	int idx = 0;

	len = max - min;
	arr = malloc(len * sizeof(*arr));

	if (arr == NULL) exit(EXIT_FAILURE);

	if (min < 2) min = 2;

	for (int num = min; num <= max; num++)
	{
		isPrime = 1;

		for (int divisor = 2; divisor <= num / 2; divisor++)
		{
			if (num % divisor == 0)
			{
				isPrime = 0;

				break;
			}
		}

		if (isPrime)
		{
			arr[idx] = num;
			idx++;
		}
	}

	*count = idx;

	return arr;
}

void printPrimeNumsInOctal(int min, int max)
{
	int count;
	int * arr;
	int decimal, octal;

	arr = getPrimeNums(min, max, &count);

	printf(
		"Prime numbers from %d to %d in octal and decimal numeral systems: \n",
		min, max
	);

	for (int i = 0; i < count; i++)
	{
		decimal = arr[i];
		octal = decimalToOctal(decimal);

		printf("In decimal: %d \t\t In octal: %d \n", decimal, octal);
	}

	free(arr);
}