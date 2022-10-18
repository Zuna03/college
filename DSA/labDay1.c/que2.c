#include <stdio.h>

int main()
{
   printf("Enter size of the array : ");
  int n;
  scanf("%d",&n);

  int arr[n];

  printf("Enter elements in array : ");
  for (int i = 0; i < n; i++)
  {
       scanf("%d",&arr[i]);
  }

  int start=0;
  int end=n-1;

  while (start < end)
  {
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;

    start++;
    end--;
  }
  
  printf("reverse array is :- ");

  for (int i = 0; i <n; i++)
  {
      printf("%d ",arr[i]);
  }
  
  return 0;
}