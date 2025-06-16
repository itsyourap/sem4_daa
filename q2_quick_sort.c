#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int arr[], int min, int max, int n)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = min + rand() % (max - min + 1);
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%3d", arr[i]);
  }
  printf("\n");
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i + 1, high);
  return i + 1;
}

void quickSort(int arr[], int low, int high, int n)
{
  if (low < high)
  {
    int j = partition(arr, low, high);
    printf("Array after Partitioning w.r.t. %d:\n", arr[j]);
    printArray(arr, n);
    quickSort(arr, low, j - 1, n);
    quickSort(arr, j + 1, high, n);
  }
}

int main()
{
  srand(time(0));
  int n, max, min;
  printf("Enter Array Length, MAX , MIN value respectively: ");
  scanf("%d %d %d", &n, &max, &min);
  int arr[n];
  generateArray(arr, min, max, n);
  printf("Given unsorted Array: \n");
  printArray(arr, n);
  printf("---- Quick Sort Steps ----\n");
  quickSort(arr, 0, n - 1, n);
  printf("\nSorted Array: \n");
  printArray(arr, n);
}