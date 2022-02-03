/*
    TASK:Latch
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],h[1010][1010];
long long dp[1010][1010];
struct A{
    int j,h;
};
stack < A > st;
int main()
{
    int n,m,l;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            h[i][j]=1;
            if(a[i][j]==a[i-1][j]){
                h[i][j]+=h[i-1][j];
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",h[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            while(!st.empty() && a[i][st.top().j]==a[i][j] && st.top().h>=h[i][j]) st.pop();
            l=0;
            if(!st.empty()) l=st.top().j;
            // printf("%d ",l);
            dp[i][j]=h[i][j]*(j-l);
            if(!st.empty() && a[i][st.top().j] == a[i][j]){ dp[i][j]+=dp[i][st.top().j];}
            st.push({j,h[i][j]});
        }
        while(!st.empty()) st.pop();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]+=(dp[i-1][j]+ dp[i][j-1] - dp[i-1][j-1]);
        }
    }
    printf("%lld",dp[n][m]);
    return 0;
}