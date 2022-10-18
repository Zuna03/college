#include <stdio.h>
#include<stdlib.h>

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

  int minNum=arr[0];
  int maxNum=arr[0];
 

  for(int i=1; i<n; i++)
    {
         if(minNum>arr[i])
		    minNum=arr[i];   
		   
         if(maxNum<arr[i])
		    maxNum=arr[i];       
    }

  printf("max num is %d and min num is %d ",maxNum,minNum);
  

  
  return 0;
}