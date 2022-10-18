#include <stdio.h>

int main()
{
  printf("Enter size of the array : ");
  int n;
  scanf("%d", &n);

  int arr[n];

  printf("Enter elements in array : ");
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("enter lower range :");
  int a;
  scanf("%d", &a);

  printf("enter upper range :");
  int b;
  scanf("%d", &b);

  int count = 0;

  int lowerRange = 0;
  int upperRange = 0;

  for (int i = 0; i < n; i++)
  {
    int temp1 = i;
    if (arr[i] == a)
    {
      if (lowerRange == 0)
      {
        lowerRange = temp1;
      }
    }

    if (arr[i] == b)
    {
      if (upperRange == 0)
      {
        upperRange = temp1;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (i >= lowerRange && i <= upperRange)
    {
      count++;
    }
  }

  printf("number of elements in range are %d ", count);

  return 0;
}