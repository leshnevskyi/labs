#include <stdio.h>

#define MIN_NUM 2

int decimalToBinary(int num);

int main()
{
	int n, bin, digit = 0;
	int inputVal;

	printf("n = ");
	inputVal = scanf("%d", &n);

	if (!inputVal)
	{
		printf("The input value has to be of type int.");

		return 5;
	}

	for (int num = MIN_NUM; num <= n; ++num)
	{
		bin = decimalToBinary(num);

		for (int i = 0; bin; ++i, bin /= 10)
		{
			digit = bin % 10;

			if (i % 2 && digit) break;

			if (!(bin / 10)) printf("%d\n", num);
		}
	}

	return 0;
}

int decimalToBinary(int num)
{
	int bin = 0, rem = 0, place = 1;

	while (num)
	{
		rem = num % 2;
		num /= 2;
		bin += rem * place;
		place *= 10;
	}

	return bin;
}