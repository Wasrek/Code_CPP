/*
    TASK:NC_Flow And Fall
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],di[]={0,0,1,-1},dj[]={1,-1,0,0},dp[110][110],n,m;
int dfs(int i,int j){
    if(dp[i][j]!=-1)    return dp[i][j];
    int ii,jj,ma = 0,k;
    for(k=0;k<4;k++){
        ii = i+di[k];
        jj = j+dj[k];
        if(ii<1 || ii>n || jj<1 || jj>m)    continue;
        if(a[ii][jj]>=a[i][j])               continue;
        ma=max(ma,dfs(ii,jj));
    }
    return dp[i][j] = ma+1;
}
int main(){
    int i,j,ma=1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            ma = max(ma,dfs(i,j));
        }
    }
    printf("%d\n",ma);
}
/*
3 3
1 2 3
4 5 6
7 8 9

2 3
2 1 2
1 2 1
*/
