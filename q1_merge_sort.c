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

void merge(int arr[], int low, int mid, int high, int n)
{
  int i = low, j = mid + 1, k = low;
  int temp[100];
  while (i <= mid && j <= high)
  {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= high)
    temp[k++] = arr[j++];
  for (int f = low; f <= high; f++)
    arr[f] = temp[f];
  printf("Array after Merging index from %d to %d:\n", low, high);
  printArray(arr, n);
}

void mergeSort(int arr[], int low, int high, int n)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, n);
    mergeSort(arr, mid + 1, high, n);
    merge(arr, low, mid, high, n);
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
  printf("---- Merge Sort Steps ----\n");
  mergeSort(arr, 0, n - 1, n);
  printf("\nSorted Array: \n");
  printArray(arr, n);
}