#include<stdio.h>
#include<math.h>
int main()
{
int a=0,z,N,l;
float x,y,m;
scanf(" %d",&N);
for(x=-1;x<999;x++)
{
y=pow(10.00,(x+1.00));z=y;
m=pow(10.00,x);l=m;
if(N%z==0){a=a+z;}else{a=a-l;break;}
}
printf("%d ",a);
}
