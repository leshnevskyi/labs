#include <math.h>

float calcExp(float x)
{
  float y;
  
  y = sqrt(1 - cos(2 * x));
  
  return y;
}
