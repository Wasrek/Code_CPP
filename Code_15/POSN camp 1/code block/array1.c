#include<stdio.h>
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   int x[n][m];
   int r,c;
   for(r=0;r<n;r++)
   {
      for(c=0;c<m;c++)
      {
         scanf("%d",&x[r][c]);
      }
   }
   for(r=0;r<n;r++)
   {
      for(c=0;c<m;c++)
      {
         printf("%d  ",x[r][c]);
      }
   }
   printf("\n");
   for(r=(n-1);r>=0;r--)
   {
      for(c=(m-1);c>=0;c--)
      {
         printf("%d  ",x[r][c]);
      }
   }
   printf("\n");
   for(c=0;c<m;c++)
   {
      for(r=0;r<n;r++)
      {
         printf("%d  ",x[r][c]);
      }
   }
   printf("\n");
   for(c=(m-1);c>=0;c--)
   {
      for(r=(n-1);r>=0;r--)
      {
         printf("%d  ",x[r][c]);
      }
   }



}
