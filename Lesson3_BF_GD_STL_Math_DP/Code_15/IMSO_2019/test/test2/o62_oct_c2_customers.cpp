/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long v[150000],sh[150000];
vector< int > g[120010];
int main()
{
    int n,m,q,p,a,b,opr;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&p);
        for(int j=1;j<=p;j++){
            scanf("%d",&a);
            g[a].push_back(i);
        }
    }
    while(q--){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&a,&b);
            sh[a]=b;
            // for(auto x: g[a]){
            //     v[x]-=sh[a];
            //     v[x]+=b;
            // }
            // sh[a]=b;
        }else{
            scanf("%d",&a);
            int now=0;
            for(auto x: g[a])now+=sh[x];
            printf("%lld\n",now);
            // printf("%lld\n",v[a]);
        }
    }
    return 0;
}