/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1000100
long long v[N],dp[N],qs[N];
long long sol(long long a,long long b,long long c,long long x){
    return (a*x*x)+(b*x)+c;
}
int main()
{
    long long n,a,b,c,l,r,mid;
    double ma,zer,zel,k,mv;
    scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
    long long now,la=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        qs[i]=qs[i-1]+v[i];
        dp[i]=LLONG_MIN;
        for(int j=la;j<i;j++){
            now=dp[i];
            dp[i]=max(dp[i],dp[j]+sol(a,b,c,qs[i]-qs[j]));
            if(now<=dp[j]+sol(a,b,c,qs[i]-qs[j])){
                // printf("%d %d\n",i,j);
                la=j;
            }else{
                // printf("no %d %d\n",i,j);
            }
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
/*
10
-1 10 -20
1 2 1 1 3 2 4 1 1 1
ans:15
*/