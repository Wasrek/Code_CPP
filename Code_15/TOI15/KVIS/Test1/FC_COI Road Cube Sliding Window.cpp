/*
    TASK:FC_COI Road Cube
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110][10010],b[110][10010],dp[110][10010];
deque<long long> dq;
int main(){
    long long n,m,k,i,j,l,ma,cou,ii;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            if(i==n)
            dp[i][j]=b[i][j]=a[i][j];
        }
    }
    for(i=n-1;i>=1;i--){
        for(j=1;j<=min(k,m);j++){
            while(!dq.empty() && dp[i+1][j]>dp[i+1][dq.back()])dq.pop_back();
            dq.push_back(j);
        }
        for(j=1;j<=m;j++){
            if(j+k<=m){
                while(!dq.empty() && dp[i+1][dq.back()]<=dp[i+1][j+k])dq.pop_back();
                dq.push_back(j+k);
            }
            while(!dq.empty() && dq.front()<j-k)dq.pop_front();
            dp[i][j]=a[i][j]+dp[i+1][dq.front()];
        }
        while(!dq.empty())dq.pop_back();
    }
    ma=0;
    for(j=1;j<=m;j++){
        ma=max(ma,dp[1][j]);
    }
    printf("%lld\n",ma);
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
