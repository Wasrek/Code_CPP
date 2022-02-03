#include<stdio.h>
int main()
{
   int x,r,c;
   scanf("%d",&x);
   for(r=1;r<=x;r++)
   {
      for(c=r;c!=r+x;c++)
      {
         printf("%d",c);
      }
      printf("\n");
   }

      for(r=1;r<=x;r++)
   {
      for(c=r;c!=r+x;c++)
      {
         if(c>x)
         {
            printf("%d",c%x);
         }else
         printf("%d",c);
      }
      printf("\n");
   }
}
