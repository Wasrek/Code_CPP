#include<stdio.h>
int main()
{
   int a,b,x;
   scanf("%d %d",&a,&b);
   for(x=a;x<=b;x++)
   {
      if(x%400==0 || (x%4==0 && x%100!=0))
      {
        printf("%d\n",x);
      }
   }

}
