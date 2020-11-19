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
int a=n[1],b=n[1];
for(y=1;y<=N;y++)
{
 if(n[y]>a){
 a=n[y];
 }
 if(n[y]<b){
 b=n[y];
 }
}

printf("%d\n%d",b,a);
return 0;
}

