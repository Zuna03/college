#include <stdio.h>


int main()
{
  printf("Enter size of the array : ");
  int n;
  scanf("%d",&n);
  
  

  int arr[n];

  printf("Enter elements in array : ");
  int i;
  for ( i = 0; i < n; i++)
  {
       scanf("%d",&arr[i]);
  }

  printf("Enter element need to be searched : ");
  int k;
  scanf("%d",&k);

  for ( i = 0; i < n; i++)
  {
      if(arr[i]==k)
      {
          printf("element is found");
          break;
      }
  }
  if(i==n)
  {
      printf("element is not found");
  }
  
  return 0;
}