#include <stdio.h>

#define X 7
#define Y 7
#define Z 7

int main()
{
	int w = -1;

	#if X > 0
		w = ((X && Y) && (X || Z)) && (!X ^ Y);
		puts("First one!");
	#elif !X
		w = ((X || Y) && (Z || Y)) && (Z || X);
		puts("Second one!");
		AA
	#endif

	if (w >= 0) printf("%u", w);
	else puts("None of the conditions is met.");

	return 0;
}