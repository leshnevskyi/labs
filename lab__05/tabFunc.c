#include <stdio.h>
#include "utils.h"

void tabFunc(float lowerBound, float upperBound, float step)
{
  double y;

  printf("x: ");

  for (float x = lowerBound; x <= upperBound; x += step)
  {
    printf("%10f \t", x);
  }

  puts("\n");
  printf("y: ");

  for (float x = lowerBound; x <= upperBound; x += step)
  {
    y = calcExp(x);

    printf("%10f \t", y);
  }

  puts("\n");
}
