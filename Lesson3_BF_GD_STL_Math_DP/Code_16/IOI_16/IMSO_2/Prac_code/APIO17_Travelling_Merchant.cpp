/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long b[110][1100],s[110][1100],dis[110][110],pf[110][110],eff[110][110];
int main()
{
    int n,m,k,u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            scanf("%lld %lld",&b[i][j],&s[i][j]);
        }
        for(int j=1;j<=n;j++){
            dis[i][j]=2e9;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=w;
    }
    for(int p=1;p<=n;p++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int p=1;p<=k;p++){
                if(dis[i][j]<2e9) pf[i][j]=max(pf[i][j],(s[j][p]!=-1 && b[i][p]!=-1) ? s[j][p]-b[i][p] : 0);
                else pf[i][j]=-2e9;
                //buy i sell j
            }
            // printf("%lld ",pf[i][j]);
        }
        // printf("\n");
    }
    //pf-num*dis + + + >=0
    long long l=0,r=2e9,mid,ma;
    while(l<r){
        mid=(l+r+1)/2;
        // printf("%lld\n",mid);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                eff[i][j]=-2e9;
                if(dis[i][j]<2e9 && i!=j) eff[i][j]=pf[i][j]-(mid*dis[i][j]);
            }
        }
        for(int p=1;p<=n;p++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][p]<2e9 && dis[p][j]<2e9)eff[i][j]=max(eff[i][j],eff[i][p]+eff[p][j]);
                }
            }
        }
        ma=-2e9;
        for(int i=1;i<=n;i++) ma=max(ma,eff[i][i]);
        if(ma>=0) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",r);
    return 0;
}