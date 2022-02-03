/*
    TASK:FC_Subway
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000010];
int d[550][550];
int main(){
    int n,m,j,s,now,i,k,q,a,b,ans;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&s);
        for(j=1;j<=s;j++){
            scanf("%d",&now);
            g[now].push_back(i);
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            if(i!=j)d[i][j]=1e9;
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<g[i].size();j++){
            for(k=j+1;k<g[i].size();k++){
                if(g[i][j]!=g[i][k]){
                    d[g[i][j]][g[i][k]]=d[g[i][k]][g[i][j]]=1;
                }
            }
        }
    }
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=m;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        ans=1e9;
        scanf("%d %d",&a,&b);
        for(i=0;i<g[a].size();i++){
            for(j=0;j<g[b].size();j++){
                ans=min(ans,d[g[a][i]][g[b][j]]);
            }
        }
        if(ans>=1e9)printf("impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}
/*
15 5
6 1 2 3 4 2 5
2 6 7
4 1 6 8 9
4 10 11 12 13
3 14 11 15
6
9 2
10 13
10 5
3 7
6 14
15 12
*/
