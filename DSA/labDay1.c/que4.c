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

  int temp;

  int counter = 1;
  while (counter < n)
  {
    for (int i = 0; i < n - counter; i++)
    {

      if (arr[i + 1] < arr[i])
      {
        int temp;
        temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
      }
    }
    counter++;
  }

  printf("sorted array is :");

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}