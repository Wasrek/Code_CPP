#include<stdio.h>
int main()
{
   int a,y,z;
   scanf(" %d",&a);
   int n=(2*a)-1;
   int x;
   for(x=1;x<=n;x+=2)
   {
      y=((n-x)/2);
      for(z=1;z<=y;z++)
      {
         printf("+");
      }
       for(z=1;z<=x;z++)
      {
         printf("0");
      }
       for(z=1;z<=y;z++)
      {
         printf("+");
      }
      printf("\n");
   }
   for(x=(n-2);x>=1;x-=2)
   {
      y=((n-x)/2);
      for(z=1;z<=y;z++)
      {
         printf("+");
      }
       for(z=1;z<=x;z++)
      {
         printf("0");
      }
       for(z=1;z<=y;z++)
      {
         printf("+");
      }
      printf("\n");
   }
}
