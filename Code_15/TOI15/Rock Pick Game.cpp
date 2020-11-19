/*
    TASK:Rock Pick Game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[150],dp[150][150];
int pick(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l>r)return 0;
    int maxx=0;
    maxx=max(maxx,pick(l+2,r)+a[l]);
    maxx=max(maxx,pick(l+1,r-1)+a[l]);
    maxx=max(maxx,pick(l+1,r-1)+a[r]);
    maxx=max(maxx,pick(l,r-2)+a[r]);
    return dp[l][r]=maxx;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=(2*n);i++){
        scanf("%d",&a[i]);
    }
    memset(dp,-1,sizeof dp);
    printf("%d\n",pick(1,2*n));
    return 0;
}
