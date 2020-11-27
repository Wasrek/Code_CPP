/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[3][10010];
struct A{
    long long j,v;
};
deque< A > dq;
int main()
{
    int n,m,k,pj;
    long long ma=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        pj=1;
        for(int j=1;j<=m;j++){
            scanf("%lld",&dp[i%2][j]);
            // printf("%d %d %d %d\n",i,n,j,m);
            if(i==1) continue;
            for(;pj<=j+k && pj<=m;){
                while(!dq.empty() && dq.back().v<=dp[(i-1)%2][pj]) dq.pop_back();
                while(!dq.empty() && dq.front().j<j-k) dq.pop_front();
                dq.push_back({pj,dp[(i-1)%2][pj]});
                // printf("-- %lld %lld\n",pj,dq.front().v);
                pj++;
            }
            while(!dq.empty() && dq.front().j<j-k){
                // printf("ch %d %d %d\n",i,j,dq.front().j);
                dq.pop_front();
            }
            dp[i%2][j]+=dq.front().v;
            // printf("dp %d %d %lld\n",i,j,dp[i%2][j]);
            if(i==n) ma=max(ma,dp[i%2][j]);
        }
        // printf("here\n");
        while(!dq.empty()){dq.pop_back();}
        // printf("here\n");
    }
    printf("%lld\n",ma);
    return 0;
}
/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0 
*/