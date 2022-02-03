/*
    TASK:Parenthes2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char s[210];
long long dp[3][210][210],ch[3][210][210];
long long play(int typ,long long l,long long r){
    if(dp[typ][l][r]!=-1)return dp[typ][l][r];
    if((r-l+1)%2==1) return dp[0][l][r]=dp[1][l][r]=0;
    if(r-l+1==2){
        long long res;
        if(s[l]=='?' && s[r]=='?')res=3;
        else if(s[l]=='?' || s[r]=='?'){
            res = s[l]=='(' || s[l]=='[' || s[l]=='{' || s[r]==')' || s[r]==']' || s[r]=='}';
        }else{
            res = s[l]=='(' && s[r]==')' || s[l]=='{' && s[r]=='}' || s[l]=='[' && s[r]==']';
        }
        if(res>99999)ch[0][l][r]=ch[1][l][r]=1;
        return dp[0][l][r]=dp[1][l][r]=res%100000;
    }
    if(typ==0){
        long long res,now;
        if(s[l]=='?' && s[r]=='?')res=3;
        else if(s[l]=='?' || s[r]=='?'){
            res = s[l]=='(' || s[l]=='[' || s[l]=='{' || s[r]==')' || s[r]==']' || s[r]=='}';
        }else{
            res = s[l]=='(' && s[r]==')' || s[l]=='{' && s[r]=='}' || s[l]=='[' && s[r]==']';
        }
        now=res*play(1,l+1,r-1);
        if(now>99999)ch[0][l][r]=1;
        return dp[0][l][r]=now%100000;
    }
    long long ans=0,i,now=0,nn=0;
    for(i=l+1;i<=r-2;i++){
        now=play(0,l,i)*play(1,i+1,r);
        nn+=now;
        ans+=(now)%100000;
        if(nn>99999)ch[1][l][r]=1;
    }
    return dp[1][l][r]=(ans+play(0,l,r))%100000;
}
int main(){
    long long n,ans;
    memset(dp,-1,sizeof dp);
    scanf("%lld",&n);
    scanf(" %s",s+1);
    ans=play(1,1,n)%100000;
    if(!ch[1][1][n])
    printf("%lld\n",ans);
    else {
        printf("%05lld\n",ans);
    }
}
