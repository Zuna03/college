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
  int i;
  int j;
  for ( i = 0; i < n; i++)
  {
      int temp=arr[i];

      for ( j = i+1; j<n; j++)
      {
          if(temp<arr[j])
          {
              printf("%d , %d \n", arr[i],arr[j]);
              break;
          }
      }
      if(j==n)
      {
           printf("%d , -1 \n",arr[i]);
      }
      
  }
  
  return 0;
}