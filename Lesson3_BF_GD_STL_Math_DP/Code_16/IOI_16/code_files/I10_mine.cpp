/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
};
int a[4][1010][1010],qsk[4][1010][1010],ma[4][1010][1010];
deque< A > dq;
int main()
{
    int n,k,ans=0;
    scanf("%d %d",&n,&k);
    for(int t=1;t<=3;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[t][i][j]);
                a[t][i][j]+=(a[t][i-1][j]+a[t][i][j-1]-a[t][i-1][j-1]);
            }
        }
    }
    for(int t=1;t<=3;t++){
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                qsk[t][i][j]=a[t][i][j]-a[t][i-k][j]-a[t][i][j-k]+a[t][i-k][j-k];
            }
        }
    }
    if(k>=n){
        printf("%d\n",qsk[1][n][n]+qsk[2][n][n]+qsk[3][n][n]);
        return 0;
    }
    for(int t=1;t<=3;t++){
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                while(!dq.empty() && dq.front().i<=j-k) dq.pop_front();
                while(!dq.empty() && dq.back().v<=qsk[t][i][j]) dq.pop_back();
                dq.push_back({j,qsk[t][i][j]});
                ma[t][i][j]=dq.front().v;
            }
            while(!dq.empty()) dq.pop_back();
        }
    }
    for(int t=1;t<=3;t++){
        for(int j=k;j<=n;j++){
            for(int i=k;i<=n;i++){
                while(!dq.empty() && dq.front().i<=i-k) dq.pop_front();
                while(!dq.empty() && dq.back().v<=ma[t][i][j]) dq.pop_back();
                dq.push_back({i,ma[t][i][j]});
                ma[t][i][j]=dq.front().v;
            }
            while(!dq.empty()) dq.pop_back();
        }
    }
    int now=0;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            now=0;
            for(int t=1;t<=3;t++){
                now+=ma[t][i][j];
            }
            ans=max(ans,now);
        }
    }
    printf("%d\n",ans);
    return 0;
}