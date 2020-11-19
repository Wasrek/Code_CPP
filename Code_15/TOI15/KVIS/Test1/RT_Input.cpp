/*
    TASK:RT_Input
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int b[1010],a[1010],c[1010],dp[1010][1010];
int main(){
    int q,n,m,i,j,len,now,cou;
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        len=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            len+=c[i];
        }
        cou=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=c[i];j++){
                b[++cou]=i;
            }
        }
        a[1]=1;
        a[len]=n;
        for(i=1;i<=m;i++){
            scanf("%d",&now);
            a[now]=b[now];
        }
        dp[1][1]=1;
        for(i=1;i<=len;i++){
            if(a[i]==0){
            for(j=1;j<=n;j++){
                dp[i][j]+=dp[i-1][j]+dp[i-1][j-1];
                dp[i][j]%=9901;
            }
            }else{
                j=a[i];
                dp[i][j]+=dp[i-1][j]+dp[i-1][j-1];
                dp[i][j]%=9901;
            }
        }
        printf("%d\n",dp[len][n]);
    }
}
