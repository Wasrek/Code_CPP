/*
    TASK:NC_Invitation Coded
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
vector<int> ans;
int main(){
    int len,i,cou,j,l=10,k,ma;
    while(l--){
    scanf(" %s",a+1);
    len=strlen(a+1);
    cou=len;ma=1;
    memset(dp,0,sizeof dp);
    for(i=1;i<=len;i++){
        a[i]=toupper(a[i]);
//        if(a[i]>'Z'){
//            a[i]-=('z'-'Z');
//        }
        dp[i][i]=1;
    }
    for(i=1;i<=len-1;i++){
        if(a[i]==a[i+1])dp[i][i+1]=1,ma=2;
    }
    for(k=3;k<=len;k++){
        for(i=1;i<=len-k+1;i++){
            j=i+k-1;
            if(a[i]==a[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                ma=max(ma,k);//ma=k;
            }
        }
    }
    ma%=10;
    ans.push_back(ma);
    }
    for(auto x: ans){
        printf("%d",x);
    }
}
