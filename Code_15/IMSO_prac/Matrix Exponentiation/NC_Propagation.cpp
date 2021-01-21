/*
    TASK:NC_Propagation
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#define mod 10007
using namespace std;
struct A{
    int a[205][205];
};
int n;
A temp,a[30],ans;
void mul(A *a,A *b){
    memset(temp.a,0,sizeof(temp.a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                temp.a[i][j]+=a->a[i][k]*b->a[k][j];
                temp.a[i][j]%=mod;
            }
        }
    }
}
int main()
{
    int m,i,s,e,t;
    scanf("%d %d %d",&n,&m,&t);
    for(i=1;i<=n;i++){
        a[0].a[i][i]=1;
    }
    while(m--){
        scanf("%d %d",&s,&e);
        a[0].a[s][e]=1;
        a[0].a[e][s]=1;
    }
    for(i=1;i<30;i++){
        mul(&a[i-1],&a[i-1]);
        a[i]=temp;
    }
    for(i=1;i<=n;i++){
        ans.a[i][i]=1;
    }
    for(i=0;i<30;i++){
        if((1ll<<i)&t){
            mul(&a[i],&ans);
            ans=temp;
        }
    }
    for(i=1;i<=n;i++){
        printf("%d ",ans.a[1][i]);
    }
    return 0;
}
