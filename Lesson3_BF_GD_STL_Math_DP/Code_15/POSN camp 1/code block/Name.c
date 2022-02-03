#include<stdio.h>
char n[1200];
int main()
{
   int x,y,r,i,k;
   scanf(" %d",&r);
   while(r--)
   {
      scanf(" %s",n);
      x=strlen(n);
      for(y=0;y<x;y=i)
      {
         for(i=y+1,k=1;i<x;i++)
         {
            if(n[y]==n[i])
            {
               k++;
            }else
            break;
         }printf("%d%c",k,n[y]);
      }
   }
}
