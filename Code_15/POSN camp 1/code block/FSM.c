#include<stdio.h>
int main()
{
   char n[120];
   int x,y;
   scanf(" %s",n);
   x=strlen(n);
   printf("%d ",x);
   for(y=0;y<x;y++){
   if(n[y]==n[y+1]){
      printf("reject");
      return 0;
      }
   }
   printf("accept");
   return 0;
}
