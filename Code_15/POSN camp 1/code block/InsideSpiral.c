#include<stdio.h>
int main()
{
   int x,y,r;
   scanf("%d %d",&x,&y);
   if(x>y)
   {
      printf("%d",2*y-1);
   }else
   if(x<y)
   {
      printf("%d",2*x-2);
   }else{
   printf("%d",2*x-2);
   }
}
