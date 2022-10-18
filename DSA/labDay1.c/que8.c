#include <stdio.h>

int main()
{
  printf("Enter size of matrix :");
  int n;
  scanf("%d",&n);

  int arr[n][n];
  
  printf("Enter elements of matrix :");

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          scanf("%d",&arr[i][j]);
      }
      
  }
  
  int count=0;

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
         if(arr[i][j] != 0)
         {
             count++;
         }
      }
  }

  printf("The number of non-zero elements in square matrix are %d \n", count);

  int sum=0;

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          if(j > i)
          {
              sum+=arr[i][j];
          }  
      }   
  }

  printf("The sum of elements above the leading diagonal is : %d \n",sum);

  printf("The elements below minor diagonal are : ");

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          if(j >= n-i)
          {
              printf("%d ",arr[i][j]);
          }  
      }
  }   
  printf("\n");
  
  int product=1;

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          if(i==j || j==n-i-1)
          {
              product=product*arr[i][j];
          }  
      }
  }

  printf("The product of elements of diagonal is : %d \n",product);
  
  return 0;
}