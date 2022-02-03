/*
    TASK:Beta mode
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[10010],b[10010];
int dp[2][10010];
int main()
{
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    int lena,lenb,ans=0,now;
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i]==b[j]){
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                if(ans<dp[i%2][j]){
                    ans=dp[i%2][j];
                    now=j;
                }
            }else{
                dp[i%2][j]=0;
            }
        }
    }
    for(int i=now-ans+1;i<=now;i++){
        printf("%c",b[i]);
    }
    return 0;
}