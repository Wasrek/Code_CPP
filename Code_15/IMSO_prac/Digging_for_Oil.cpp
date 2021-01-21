/*
    TASK:Digging_for_Oil
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int qs[1510][1510],nw[1510][1510],ne[1510][1510],sw[1510][1510],se[1510][1510];
int main()
{
    int n,m,k,i,j,ans=0,now;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&qs[i][j]);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+qs[i][j];
        }
    }
    for(i=n; i>=k; i--)
    {
        for(j=m; j>=k; j--)
        {
            qs[i][j]=qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k];
        }
    }
    for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            nw[i][j]=max(nw[i-1][j],max(nw[i][j-1],qs[i][j]));
        }
    }
    for(i=k;i<=n;i++){
        for(j=m;j>=k;j--){
            ne[i][j]=max(ne[i-1][j],max(ne[i][j+1],qs[i][j]));
        }
    }
    for(i=n;i>=k;i--){
        for(j=k;j<=m;j++){
            sw[i][j]=max(sw[i+1][j],max(sw[i][j-1],qs[i][j]));
        }
    }
    for(i=n;i>=k;i--){
        for(j=m;j>=k;j--){
            se[i][j]=max(se[i+1][j],max(se[i][j+1],qs[i][j]));
        }
    }
    for(i=k;i<=n-k;i++){
        for(j=k;j<=m-k;j++){
            now = nw[i][j]+ne[i][j+k]+sw[i+k][m];
            ans = max(ans,now);
        }
    }
    for(i=k;i<=n-k;i++)
    {
        for(j=2*k;j<=m;j++){
            now = ne[i][j]+se[i+k][j]+nw[n][j-k];
            ans = max(ans,now);
        }
    }
    for(i=2*k;i<=n;i++){
        for(j=k;j<=m-k;j++){
            now = sw[i][j]+se[i][j+k]+nw[i-k][m];
            ans = max(ans,now);
        }
    }
    for(i=k;i<=n-k;i++){
        for(j=k;j<=m-k;j++){
            now = nw[i][j]+sw[i+k][j]+ne[n][j+k];
            ans = max(ans,now);
        }
    }
    for(i=k;i<=n;i++){
        for(j=2*k;j<=m-k;j++){
            now = qs[i][j]+nw[n][j-k]+ne[n][j+k];
            ans = max(ans,now);
        }
    }
    for(i=2*k;i<=n-k;i++){
        for(j=k;j<=m;j++){
            now = qs[i][j]+nw[i-k][m]+sw[i+k][m];
            ans = max(ans,now);
        }
    }
    printf("%d\n",ans);
}
/*
12 12 3
2 3 2 3 3 3 3 2 3 3 2 2
3 3 3 2 2 3 3 4 2 2 3 4
3 4 3 4 2 3 4 3 4 3 2 3
4 4 4 5 3 2 4 4 4 3 3 3
4 5 3 3 6 6 6 3 5 2 3 3
5 5 4 5 5 6 6 4 5 3 2 3
3 4 2 3 6 7 6 3 3 3 3 4
2 3 3 3 2 2 2 2 3 4 3 3
2 2 4 3 4 3 2 3 3 2 4 2
3 3 3 3 2 4 3 3 3 2 3 4
2 3 2 3 4 4 3 3 2 3 2 3
3 3 3 3 3 3 4 2 3 4 3 3
*/
