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

void adjustHeap(int arr[], int parent, int heapSize)
{
  int temp = arr[parent];
  int child = 2 * parent + 1;
  while (child < heapSize)
  {
    // If right child exists and is greater than left child
    if (child + 1 < heapSize && arr[child] < arr[child + 1])
      child++;
    // If parent is larger than or equal to the largest child, done
    if (temp >= arr[child])
      break;
    arr[parent] = arr[child];
    parent = child;
    child = 2 * parent + 1;
  }
  arr[parent] = temp;
}

void makeMaxHeap(int arr[], int n)
{
  for (int i = (n - 2) / 2; i >= 0; i--)
    adjustHeap(arr, i, n);
}

void heapSort(int arr[], int n)
{
  makeMaxHeap(arr, n);
  printf("Array after building Max - Heap: \n");
  printArray(arr, n);
  for (int i = n - 1; i >= 1; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    adjustHeap(arr, 0, i);
    printf("Array after heapify element %d:\n", arr[i]);
    printArray(arr, n);
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
  printf("---- Heap Sort Steps ----\n");
  heapSort(arr, n);
  printf("\nSorted Array: \n");
  printArray(arr, n);
}