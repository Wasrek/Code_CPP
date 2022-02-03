#include<stdio.h>

int main()
{
   int d,k=0,y,x;
   int n[3][3];
   printf("Enter number : ");
   scanf(" %d",&d);
   k=d+8;

     x=0;
        {
         for(y=0;y<3;y++)
        {
           n[x][y]=k;
           k=k-1;
        }
        }
     x=1;
        for(y=2;y>=0;y--)
        {
           n[x][y]=k;
           k=k-1;
        }
  x=2;
        {
         for(y=0;y<3;y++)
        {
           n[x][y]=k;
           k=k-1;
        }
        }


   for(x=0;x<3;x++)
   {
      for(y=0;y<3;y++)
      {
         printf("%d ",n[x][y]);
      }
      printf("\n");
   }

}
