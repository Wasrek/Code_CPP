#include<stdio.h>
int main()
{
   char n[1020];
   int k,x,y;
   scanf(" %s %d",n,&k);
   x=strlen(n);
   k=k%x;
   for(y=(x-k);y<x;y++)
   {printf("%c",n[y]);}
   for(y=0;y<(x-k);y++)
   {printf("%c",n[y]);}
}
