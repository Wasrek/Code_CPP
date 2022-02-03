/*
    TASK:Latch
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010],h[1010][1010],dp[1010][1010],qs[1010][1010];
struct A{
    long long a,h,i,j;
};
stack< A > st;
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j]==a[i-1][j]){
                h[i][j]=h[i-1][j]+1;
            }else h[i][j]=1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",h[i][j]);
    //     }
    //     printf("\n");
    // }
    long long l,r;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            while(!st.empty() && st.top().h>=h[i][j] && st.top().a==a[i][j]){st.pop();}
            l=0;
            if(!st.empty()) l=st.top().j;
             printf("%d ",l);
            dp[i][j]=h[i][j]*(j-l);
            if(a[i][l]==a[i][j])dp[i][j]+=dp[i][l];
            st.push({a[i][j],h[i][j],i,j});
        }
        while(!st.empty())st.pop();
         printf("\n");
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            qs[i][j]=dp[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            // printf("%d ",dp[i][j]);
        }
        // printf("\n");
    }
    printf("%lld\n",qs[n][m]);
    return 0;
}