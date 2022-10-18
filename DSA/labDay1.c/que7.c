#include <stdio.h>

void swap(int* a_198,int*b_198,int*c_198)
{
   int temp_198=*c_198;
   *c_198=*b_198;
   *b_198=*a_198;
   *a_198=temp_198;

   printf("Variables after swapping in cyclic order are : a=%d , b=%d , c=%d \n", *a_198,*b_198,*c_198 );

}

int main()
{
  
  printf("Enter three elements : ");

  int a_198;
  scanf("%d",&a_198);
  int b_198;
  scanf("%d",&b_198);
  int c_198;
  scanf("%d",&c_198);

  printf("Variables before swapping in cyclic order are : a=%d , b=%d , c=%d \n", a_198,b_198,c_198 );

  swap(&a_198,&b_198,&c_198);
 
  return 0;
}