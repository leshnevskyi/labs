#include <stdio.h>
#include <math.h>

int numToReversedArr(int arr[], int num, int index);
int base5ToDecimal(int arr[], int index);

int main() 
{
  int arr[5];
  int base5Num = 0;

  scanf("%d", &base5Num);

  numToReversedArr(arr, base5Num, 0);

  int res = base5ToDecimal(arr, sizeof arr / sizeof arr[0] - 1);

  printf("The number %d in base 5 equals to %d in base 10.\n", base5Num, res);

  return 0;
}

int numToReversedArr(int arr[], int num, int index)
{
  arr[index] = num % 10;

  if (num / 10)
  {
    numToReversedArr(arr, num / 10, ++index);
  }

  return 0;
}

int base5ToDecimal(int arr[], int index)
{
  if (!index)
  {
    return arr[index];
  }

  return arr[index] * pow(5, index) + base5ToDecimal(arr, --index);
}