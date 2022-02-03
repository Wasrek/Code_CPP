/*
    TASK:Ant changeword
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
char a[1010],b[1010];
int main()
{
    int q,lena,lenb;
    scanf("%d",&q);
    while(q--){
        scanf(" %s %s",a+1,b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        for(int i=1;i<=lena;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=lenb;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=lena;i++){
            for(int j=1;j<=lenb;j++){
                if(a[i]==b[j]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}