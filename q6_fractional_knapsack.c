#include <stdio.h>

#define MAX 100

typedef struct
{
  double profit;
  double weight;
  double puw;
} Item;

double solution[MAX];

Item items[] = {
  {120.0, 20.0, 0.0},
  {280.0, 40.0, 0.0},
  {120.0, 24.0, 0.0},
  {100.0, 10.0, 0.0}
};

int numberOfItems = sizeof(items) / sizeof(items[0]);

void computePUW()
{
  int i;
  for (i = 0; i < numberOfItems; i++)
  {
    items[i].puw = items[i].profit / items[i].weight;
  }
}

void printItems(Item arr[], int size)
{
  int i;
  printf("Profit  Weight   PUW\numberOfItems");
  for (i = 0; i < size; i++)
  {
    printf("%6.2f  %6.2f %6.2f\numberOfItems", arr[i].profit, arr[i].weight, arr[i].puw);
  }
  printf("\numberOfItems");
}

void merge(int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low;
  Item temp[MAX];
  while (i <= mid && j <= high)
  {
    if (items[i].puw >= items[j].puw)
    {
      temp[k++] = items[i++];
    }
    else
    {
      temp[k++] = items[j++];
    }
  }

  while (i <= mid)
    temp[k++] = items[i++];
  while (j <= high)
    temp[k++] = items[j++];

  for (i = low; i <= high; i++)
  {
    items[i] = temp[i];
  }
}

void mergeSort(int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
  }
}

void sortbyPUW()
{
  mergeSort(0, numberOfItems - 1);
}

void FractionalKnapsack(int capacity, int numberOfItems)
{
  int i;
  computePUW();
  sortbyPUW();

  double p = 0.0;
  for (i = 0; i < numberOfItems; i++)
    solution[i] = 0.0;
  
  for (i = 0; i < numberOfItems; i++)
  {
    if (items[i].weight > capacity)
      break;
    solution[i] = 1.0;
    capacity = capacity - items[i].weight;
    p = p + items[i].profit;
  }
  if (i < numberOfItems)
  {
    solution[i] = capacity / items[i].weight;
    p = p + solution[i] * items[i].profit;
  }
  printf("\nMaximum Profit: ");
  printf("%6.2f RS", p);
}

int main()
{
  int capacity;
  computePUW();

  printf("Item List:\numberOfItems");
  printItems(items, numberOfItems);
  printf("Enter KnapSack Capacity: ");
  scanf("%d", &capacity);
  FractionalKnapsack(capacity, numberOfItems);

  return 0;
}