#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define LEN 100000

void swapInts(int * a, int * b);
int partition(int * arr, int low, int high);
void quickSort(int * arr, int low, int high);
void bubbleSort(int array[], int size);
void insertionSort(int * arr, int len);
void fillArrWithRandInts(int * arr, int len);
void printIntArr(const int * arr, int len);
int arrCmp(const int * arr1, const int * arr2, int len);

int main()
{
  int arr[LEN];
  int arrCpy[LEN];
  int areEqual = 0;
  clock_t tm;
  double timeTaken;

  fillArrWithRandInts(arr, LEN);
  memcpy(arrCpy, arr, sizeof arr);

  areEqual = arrCmp(arr, arrCpy, LEN);
  areEqual
    ? printf("Initial arrays are equal. \n")
    : printf("Initial arrays are unequal. \n");

  tm = clock(); 
  quickSort(arr, 0, LEN - 1);
  tm = clock() - tm;
  timeTaken = (double)tm / CLOCKS_PER_SEC;

  printf("It took %fs to sort the array with quick sort. \n", timeTaken);

  tm = clock();
  insertionSort(arrCpy, LEN);
  tm = clock() - tm;
  timeTaken = (double)tm / CLOCKS_PER_SEC;

  printf("It took %fs to sort the array with insertion sort. \n", timeTaken);

  areEqual = arrCmp(arr, arrCpy, LEN);
  areEqual
    ? printf("Sorted arrays are equal. \n")
    : printf("Sorted arrays are unequal. \n");

  puts("Ne zabuty perenesty tu dich v header file!");

	return 0;
}

void swapInts(int * a, int * b)
{
  int temp = *a;

  *a = *b;
  *b = temp;
}

int partition(int * arr, int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swapInts(&arr[i], &arr[j]);
    }
  }

  swapInts(&arr[i + 1], &arr[high]);

  return i + 1;
}

void quickSort(int * arr, int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

void insertionSort(int * arr, int len)
{
  for (int step = 1; step < len; step++)
  {
    int key = arr[step];
    int prevIdx = step - 1;

    while (key < arr[prevIdx] && prevIdx >= 0)
    {
      arr[prevIdx + 1] = arr[prevIdx];
      prevIdx--;
    }

    arr[prevIdx + 1] = key;
  }
}

void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];

        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void fillArrWithRandInts(int * arr, int len)
{
  srand(time(NULL));

  for (int i = 0; i < len; i++)
  {
    arr[i] = rand();
  }
}

void printIntArr(const int * arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int arrCmp(const int * arr1, const int * arr2, int len)
{
  for (int i = 0; i < len; i++)
  {
    if (arr1[i] != arr2[i]) return 0;
  }

  return 1;
}