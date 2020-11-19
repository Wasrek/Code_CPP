/*
    TASK:Drowsy Task
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[100010],n[3];
int mark[30][30],dp[100010][30];
int main(){
    int i,j,q,len,u,v,ans=1e9;
    scanf(" %s",a+1);
    len = strlen(a+1);
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf(" %s",n);
        u = n[0]-'a',v = n[1]-'a';
        mark[u][v] = mark[v][u] = 1;
    }
    for(int i=1;i<=len;i++)
        for(int j=0;j<26;j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(i=1;i<=len;i++){
        for(j=0;j<26;j++){
            dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            if(mark[j][a[i]-'a'] == 0){
                dp[i][a[i]-'a'] = min(dp[i][a[i]-'a'],dp[i-1][j]);
            }
        }
    }
    for(i=0;i<26;i++)ans = min(ans,dp[len][i]);
    printf("%d\n",ans);
}
/*
ababa
1
ab

minicontest
2
oc
mt
*/
