#include<bits/stdc++.h>
using namespace std;
int p[10],a[15],b[15],n;
void permu(int state){
    int i,j;
    for(i=1;i<=n;i++)
   {
       if(a[i]!=1){
       if(state!=1){
        a[i]=1;
        b[state]=i;
        permu(state+1);
        a[i]=0;
       }else if(p[i]!=1){
        a[i]=1;
        b[state]=i;
        permu(state+1);
        a[i]=0;
       }
       }
   }
   if(state==n){
    for(j=1;j<=n;j++)
        printf("%d ",b[j]);
    printf("\n");
   }
}
int main()
{
int i,j,m;
scanf("%d %d",&n,&m);
for(i=0;i<m;i++){
    scanf("%d",&j);
    p[j]=1;
}
permu(1);
}
