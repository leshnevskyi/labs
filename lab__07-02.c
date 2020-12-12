#include <stdio.h>
#include <math.h>

#define LOWER 0
#define UPPER 2 * M_PI

double calcFunc(double x);
void tabFuncWithForLoop(
	double (*func)(double x),
	double lowerBound,
	double upperBound,
	double step
);
void tabFuncWithWhileLoop(
	double (*func)(double x),
	double lowerBound,
	double upperBound,
	double step
);
void tabFuncWithDoWhileLoop(
	double (*func)(double x),
	double lowerBound,
	double upperBound,
	double step
);

int main()
{
	double step;
	void (* tabFunc)(
		double (*func)(double x),
		double lowerBound,
		double upperBound,
		double step
	);
	char key;

	puts(
		"Press 'f' to use the for loop, 'w' to use the while loop," 
		"or any other key to use the do while loop:"
	);
	scanf("%c", &key);

	switch (key)
	{
		case 'f':
			tabFunc = tabFuncWithForLoop;
			puts("The for loop has been used.");

			break;

		case 'w':
			tabFunc = tabFuncWithWhileLoop;
			puts("The while loop has been used.");

			break;

		default:
			tabFunc = tabFuncWithDoWhileLoop;
			puts("The do while loop has been used.");
	}

	tabFunc(calcFunc, LOWER, UPPER, 1);

	return 0;
}

double calcFunc(double x)
{
	double y;

	y = x * x * cos(x);

	return y;
}

void tabFuncWithForLoop(
	double (*func)(double x),
	double lowerBound,
	double upperBound,
	double step
)
{
	double x = lowerBound;
	double y;

	printf("x: \t");

	for (x = lowerBound; x < upperBound; x += step)
	{
		printf("%7.3lf \t", x);
	}

	printf("\ny: \t");

	for (x = lowerBound; x < upperBound; x += step)
	{
		y = func(x);
		printf("%7.3f \t", y);
	}
}

void tabFuncWithWhileLoop(
	double (*func)(double x),
	double lowerBound,
	double upperBound,
	double step
)
{
	double x = lowerBound;
	double y;

	printf("x: \t");

	while (x < upperBound)
	{
		printf("%7.3lf \t", x);
		x += step;
	}

	x = lowerBound;

	printf("\ny: \t");

	while (x < upperBound)
	{
		y = func(x);
		printf("%7.3f \t", y);
		x += step;
	}
}

void tabFuncWithDoWhileLoop(
	double (*func)(double x),
	double lowerBound,
	double upperBound,
	double step
)
{
	double x = lowerBound;
	double y;

	printf("x: \t");


	do {
		printf("%7.3lf \t", x);
		x += step;
	} while (x < upperBound);

	x = lowerBound;

	printf("\ny: \t");

	while (x < upperBound)
	{
		y = func(x);
		printf("%7.3f \t", y);
		x += step;
	}
}