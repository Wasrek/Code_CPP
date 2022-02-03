#include<stdio.h>
int main()
{
   int x,y,a,b,r;
   scanf("%d%d%d%d",&x,&y,&a,&b);
   if((2*a)<b)
   {
      printf("%d",(x+y)*a);
   }else if((2*a)>=b)
   {
       if(a<b)
       {
      if(x<y)
      {
         r=(x*b)+((y-x)*a);
         printf("%d",r);
      }
      if(y<=x)
      {
         r=(y*b)+((x-y)*a);
         printf("%d",r);
      }
       }
       if(b<a)
       {
            if(x<y)
      {
         r=(x*b)+((y-x)*b);
         printf("%d",r);
      }
      if(y<=x)
      {
         r=(y*b)+((x-y)*b);
         printf("%d",r);
      }
       }
   }
}
