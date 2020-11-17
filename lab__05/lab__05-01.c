#include <stdio.h>
#include <math.h>
#include "utils.h"

#define LOWER_BOUND 0
#define UPPER_BOUND 100 * M_PI

int main()
{
  float step;
  float x, y;
  int sign;

  puts("Enter step: ");
  scanf("%f", &step);
  puts("");

  tabFunc(LOWER_BOUND, UPPER_BOUND, step);

  puts("Enter x: ");
  scanf("%f", &x);
  puts("");

  sign = getExpSign(x, &y);

  printf("Sign: %d \n" "Result = %lf \n\n", sign, y);

  return 0;
}
