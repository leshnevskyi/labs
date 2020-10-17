#include <stdio.h>
#include <math.h>

int main() 
{
	float x = 0, y = 0;
	const int a = 2;

	scanf("%f %f", &x, &y);

	float res = pow(a, pow(y, x)) + pow(pow(3, x), y);

	printf("The result is equal to %f", res);

	return 0;
}