/*
    TASK:Segi Tiga Operation
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char s[300],dp[300][300][5];
int f(int l,int r,int o){
    if(dp[l][r][o]!=-1) return dp[l][r][o];
    if(l==r){
        if(s[l]-'0'==o)return dp[l][r][o]=1;
        return dp[l][r][o]=0;
    }
    dp[l][r][o]=0;
    for(int i=l;i<r;i++){
        if(o==0){
            dp[l][r][o]|=(f(l,i,0)&f(i+1,r,2));
        }
        else if(o==1){
            dp[l][r][o]|=(f(l,i,0)&f(i+1,r,1));
            dp[l][r][o]|=(f(l,i,1)&f(i+1,r,1)|f(i+1,r,2));
            dp[l][r][o]|=(f(l,i,2)&f(i+1,r,0)|f(i+1,r,2));
        }
        else{
            dp[l][r][o]|=(f(l,i,0)&f(i+1,r,0));
            dp[l][r][o]|=(f(l,i,1)&f(i+1,r,0));
            dp[l][r][o]|=(f(l,i,2)&f(i+1,r,1));
        }
        if(dp[l][r][o]) return 1;
    }
    return dp[l][r][o];
}
int main(){
    int n;
    for(int i=0;i<20;i++){
        scanf("%d %s",&n,s);
        memset(dp,-1,sizeof dp);
        if(f(0,n-1,0))printf("yes\n");
        else printf("no\n");
    }
}
