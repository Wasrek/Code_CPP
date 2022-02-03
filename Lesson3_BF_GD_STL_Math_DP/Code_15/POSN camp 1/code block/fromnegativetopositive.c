#include<stdio.h>
#include<math.h>
int main()
{
int n,x,a;
scanf(" %d",&n);
a=abs(n);
printf(" %d\n",a);
for(x=-a;x<=a;x++)
{
printf(" %d",x);
}
}
