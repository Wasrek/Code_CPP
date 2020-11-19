/*
    TASK:Observatory
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
// #include<cstdio>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;
long long a[2010][2010],r[2010][2010],qs[2010][2010],st[2010][2010],rr[2010][2010],rqs[2010][2010],rst[2010][2010];
int main()
{
    long long n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
            r[i][j]=r[i][j-1]+a[i][j];
            st[i][j]=st[i-1][j-1]+r[i][j];
        }
        for(int j=m;j>=1;j--){
            rqs[i][j]=rqs[i-1][j]+rqs[i][j+1]-rqs[i-1][j+1]+a[i][j];
            rr[i][j]=rr[i][j+1]+a[i][j];
            rst[i][j]=rst[i-1][j+1]+rr[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%lld ",rqs[i][j]);
    //     }
    //     printf("\n");
    // }
    long long ma=-2e9,now;
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=m-k+1;j++){
        now=st[i+k-1][j+k-1]-st[i-1][j-1]-qs[i+k-1][j-1]+qs[i-1][j-1];
        ma=max(ma,now);
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
        now=rst[i][j-k+1]-rst[i-k][j+1]-rqs[i][j+1]+rqs[i-k][j+1];
        // if(i==k && j==k) printf("%lld\n",now);
        ma=max(ma,now);
        }
    }
    printf("%lld\n",ma);
    return 0;
}