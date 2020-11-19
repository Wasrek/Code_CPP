/*
    TASK:o62_oct_c2_power
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
};
A a[200010],dp[200010];
int bs[200010];
int main()
{
    int n,m,near;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
        near=lower_bound(bs+1,bs+1+n,a[i].w);

        dp[i].u=max(dp[i])
        bs[i]=a[i].v;
    }
    return 0;
}