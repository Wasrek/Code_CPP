/*
    TASK:NC_Invitation Coded
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int dp[1010][1010];
vector<int> ans;
int main(){
    int len,i,cou,j,l=10;
    while(l--){
    scanf(" %s",a+1);
    len=strlen(a+1);
    cou=len;
    for(i=1;i<=len;i++){
        a[i]=toupper(a[i]);
        b[cou]=a[i];
        cou--;
    }
    for(i=1;i<=len;i++){
        for(j=1;j<=len;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i][j-1];
        }
    }
    dp[len][len]%=10;
    ans.push_back(dp[len][len]);
    }
    for(auto x: ans){
        printf("%d",x);
    }
}
