#include <math.h>

double calcExp(float x)
{
  double y;

  y = sqrt(1 - cos(2.0 * x));

  return y;
}
