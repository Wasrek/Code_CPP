/*
    TASK:Peatt Treasure
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define INF -1000000000
int dp[310][310][310],a[310][310];
int ch(int i,int j,int k){
    int ans=INF;
    for(int r=-1;r<=1;r++){
        for(int s=-1;s<=1;s++){
            ans = max(ans,dp[i-1][j+r][k+s]);
        }
    }
    return ans;
}
int main(){
    int q,r,c,i,j,k,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
        for(i=1;i<=r+1;i++)
        for(j=0;j<=c+1;j++)
            for(k=0;k<=c+1;k++)
                dp[i][j][k]=INF;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                for(k=1;k<=c;k++){
                    if(j==k)
                    dp[i][j][k]=ch(i,j,k)+a[i][j];
                    else
                        dp[i][j][k]=ch(i,j,k)+a[i][j]+a[i][k];
                }
            }
        }
        ans=INF;
        for(j=1;j<=c;j++)
            ans=max(ans,dp[r][j][j]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
6 5
8 7 4 3 4
-8 -1 -3 -2 -5
2 8 7 1 1
3 -4 -1 -7 3
-4 -3 8 7 4
6 4 -3 -2 -1
*/
