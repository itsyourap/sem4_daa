#include <stdio.h>

#define MAX 100

typedef struct
{
  int jobNumber;
  int profit;
  int days;
} Job;

Job jobs[] = {
    {1, 200, 3},
    {2, 250, 2},
    {3, 150, 3},
    {4, 200, 1},
    {5, 300, 2},
    {6, 200, 2}};

int min(int x, int y)
{
  if (x > y)
    return y;
  return x;
}

int n = sizeof(jobs) / sizeof(jobs[0]);
int slot[MAX];
int solution[MAX];

void printJobs()
{
  int i;
  printf("Job No.  Profit  Days Req.\n");
  for (i = 0; i < n; i++)
  {
    printf("%4d %8d %8d\n", jobs[i].jobNumber, jobs[i].profit, jobs[i].days);
  }
}

void merge(int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low;
  Job temp[MAX];
  while (i <= mid && j <= high)
  {
    if (jobs[i].profit >= jobs[j].profit)
    {
      temp[k++] = jobs[i++];
    }
    else
    {
      temp[k++] = jobs[j++];
    }
  }

  while (i <= mid)
    temp[k++] = jobs[i++];
  while (j <= high)
    temp[k++] = jobs[j++];

  for (i = low; i <= high; i++)
  {
    jobs[i] = temp[i];
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

void sortbyProfit()
{
  mergeSort(0, n - 1);
}

void JSD(int n)
{
  int i, j;
  int profit = 0;
  sortbyProfit();
  for (i = 0; i < n; i++)
  {
    slot[i] = 0;
    solution[i] = -1;
  }
  for (i = 0; i < n; i++)
  {
    for (j = min(jobs[i].days, n) - 1; j >= 0; j--)
    {
      if (slot[j] == 0)
      {
        slot[j] = 1;
        solution[j] = jobs[i].jobNumber;
        profit += jobs[i].profit;
        break;
      }
    }
  }
  printf("Solution Vector: ");
  for (i = 0; i < n; i++)
    printf("%3d", solution[i]);
  printf("\n");
  printf("Total Profit: %d\n", profit);
}

int main()
{
  printf("Given Jobs:\n");
  printJobs();
  sortbyProfit();
  printf("Given Jobs After Sorting by Profit:\n");
  printJobs();
  JSD(n);
}