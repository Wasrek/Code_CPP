/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dis[1010][1010],ans[1010];
int main()
{
    long long n,k,ops,a,b,now;
    scanf("%lld %lld",&n,&k);
    ans[1]=1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            scanf("%lld",&dis[i][j]);
            if(i==1 && j==2){
                ans[2]=(dis[i][j]+1+n)%n;
                if(ans[2]==0) ans[2]=n;
            }
        }
        if(i==1 || i==2) continue;
        a=i-2;
        b=i-1;
        if(i>3 && dis[a][b]==n/2){
            a=i-3;
        }
        now=(ans[a]+dis[a][b])%n;
        if(now==0) now=n;
        if(now!=ans[b]){
            swap(a,b);
        }
        if(i>=3){
            ops=(ans[a]+(n/2))%n;
            if(ops==0) ops=n;
            if(dis[i][b]+dis[i][a]==dis[b][a]){
                ans[i]=(((ans[a]+dis[i][a])%n)+n)%n;
            }else{
                if(dis[a][i]<dis[b][i]) ans[i]=(ans[a]-dis[i][a]+n)%n;
                else ans[i]=(ans[b]+dis[i][b])%n;
            }
        }
        if(ans[i]==0) ans[i]=n;
    }
    for(int i=1;i<=k;i++){
        printf("%lld\n",ans[i]-1);
    }
    return 0;
}