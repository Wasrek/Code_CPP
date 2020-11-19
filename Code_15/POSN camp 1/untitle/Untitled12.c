#include<stdio.h>
int main()
{
   int n,y;
   scanf("%d",&n);
   float x[n+100],s=0;
   for(y=0;y<n;y++)
   {
       scanf(" %f",&x[y]);
   }
      for(y=0;y<n;y++)
   {
       s+=x[y];
   }
   printf("%.3lf\n%.3lf",s,(s/n));

   return 0;
}
