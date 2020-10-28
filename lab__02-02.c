#include <stdio.h>
#include <math.h>

int main()
{
	double lowerBound, upperBound, currEl, accuracy, x, approxVal, exactVal, diff;
	int stepsNum;

	printf("Lower bound = ");
	scanf("%lf", &lowerBound);
	printf("Upper bound = ");
	scanf("%lf", &upperBound);

	if (fabs(lowerBound) >= 1 || fabs(upperBound) >= 1)
	{
		printf(
			"The lower and the upper bounds for x must be within the function domain: |x| < 1.\n"
		);

		return 5;
	}

	printf("Accuracy of the approximate value = ");
	scanf("%lf", &accuracy);

	if (accuracy <= 0)
	{
		printf("Accuracy of the approximate value must be a positive number.");

		return 5;
	}

	printf("Number of steps = ");
	scanf("%d", &stepsNum);

	for (int i = 0; i <= stepsNum; ++i)
	{
		currEl = 1;
		approxVal = currEl;
		x = lowerBound + fabs(upperBound - lowerBound) / stepsNum * i;

		printf("\nx = %lf\n", x);

		for (int j = 1; fabs(currEl) > accuracy; ++j)
		{
			currEl = -(j + 1) * currEl / j * x;
			approxVal += currEl;
		}

		exactVal = pow((1 + x), -2);
		diff = fabs(exactVal - approxVal);

		printf("Approximate value = %lf\n", approxVal);
		printf("Exact value = %lf\n", exactVal);
		printf("Difference = %lf\n", diff);
	}

	return 0;
}