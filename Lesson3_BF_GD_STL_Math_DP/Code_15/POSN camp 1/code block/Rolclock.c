#include<stdio.h>
int main()
{
   int x,a=6;
   scanf("%d",&x);
   x=x%360;
   while(x>=30)
   {
      a=(a+1)%12;
      x=x-30;
   }
   if(x>15)
   {
      printf("%d",a+1);
   }else if(x<=15)
   {
      printf("%d",a);
   }
}
