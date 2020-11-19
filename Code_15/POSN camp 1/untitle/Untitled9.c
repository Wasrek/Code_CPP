#include<stdio.h>
void main()
{
   int x,y,z,a;
   printf("Enter number :");
   scanf(" %d",&x);

   for(y=1;y<=x;y++)
   {
            int b=x-y;
      for(z=0;z<b;z++)
      {
         printf(" ");
      }
      for(z=0;z<(y*2);z++)
      {
         printf("*");
      }
            for(z=0;z<b;z++)
      {
         printf(" ");
      }
      printf("\n");
   }
   for(y=(x-1);y>=1;y--)
   {
            int b=x-y;
      for(z=0;z<b;z++)
      {
         printf(" ");
      }
      for(z=0;z<(y*2);z++)
      {
         printf("*");
      }
            for(z=0;z<b;z++)
      {
         printf(" ");
      }
      printf("\n");
   }
}
