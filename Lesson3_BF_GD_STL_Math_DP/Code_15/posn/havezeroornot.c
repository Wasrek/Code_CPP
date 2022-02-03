#include<stdio.h>
int main()
{
int N,x,y,a=0;
scanf(" %d",&N);
int n[N];
for(x=1;x<=N;x++)
{
scanf(" %d",&n[x]);
}
for(y=1;y<=N;y++)
{
if(n[y]==0){
a=1;
printf("Have");
break;
}
}
if(a==0){
printf("Don't have");
}
}
