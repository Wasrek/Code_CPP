#include<stdio.h>
int main()
{
   int x,l,k,m=0;
   scanf("%d",&x);
   int n[x];
   for(l=0;l<x;l++)
   {
      scanf("%d",&n[l]);
   }
   scanf("%d",&k);
   int o;
   o=x-1;
   while(o>=0)
   {
      printf("%d  ",n[o]);
      if(n[o]==k)
      {
        m=m+1;
      }
      o--;
   }
   printf("\n%d",m);

}
