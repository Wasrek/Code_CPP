#include<stdio.h>
int main()
{
   double d,r,t,f,a;
   scanf("%lf %lf %lf %lf",&d,&r,&t,&f);
   a=(d/(t-r))*f;
   printf("%.2lf",a);
}
