#include<stdio.h>
int main()
{
int N,x,y;
scanf(" %d",&N);
int n[N];
for(x=1;x<=N;x++)
{
scanf(" %d",&n[x]);
}
for(y=N;y>=1;y--)
{
printf("%d\n",n[y]);
}

return 0;
}
