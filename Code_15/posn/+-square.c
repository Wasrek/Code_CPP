#include<stdio.h>
int main()
{
int N,x,y,a,b,z;
scanf(" %d",&N);
for(z=1;z<=N;z++){
a=z;
b=N-z;
for(x=1;x<=a;x++)
{
printf("+");
}
for(y=b;y>=1;y--)
{
printf("-");
}
printf("\n");
}
}
