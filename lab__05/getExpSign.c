#include "utils.h"

int getExpSign(float x, float * y)
{
  float res;

  * y = calcExp(x);
  res = * y;

  if (!res) return 0;
  if (res > 0) return 1;

  return -1;
}
