#include<stdio.h>
int main()
{
   int a,b,c,d,e,f,x,y;
   scanf("%d %d %d %d %d %d",&a,&d,&c,&e,&b,&f);
   if(a==b)
   {
      x=c;
   }else
    if(a==c)
   {
      x=b;
   }else
    if(c==b)
   {
      x=a;
   }

   if(d==e)
   {
      y=f;
   }else
    if(d==f)
   {
      y=e;
   }else
    if(f==e)
   {
      y=d;
   }

   printf("%d %d",x,y);
}
