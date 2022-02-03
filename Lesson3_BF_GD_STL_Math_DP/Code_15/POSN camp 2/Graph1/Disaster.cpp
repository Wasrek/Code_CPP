/*
    TASK:Disaster
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> g[30];
char a[5];
int deg[30],n,mark[30][30][130],ans[310];
void dfs(int u,int state){
    int i,x;
    ans[state]=u;
    if(state==n){
        for(i=0;i<=n;i++)
            printf("%c ",'A'+ans[i]);
        exit(0);
    }
    for(auto x:g[u]){
        if(mark[u][x.first][x.second]) continue;
        mark[u][x.first][x.second]=mark[x.first][u][x.second]=1;
        dfs(x.first,state+1);
        mark[u][x.first][x.second]=mark[x.first][u][x.second]=0;
    }
}
int main(){
    int i,st=-1,mi=30;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",a);
        g[a[0]-'A'].push_back(make_pair(a[1]-'A',i));
        g[a[1]-'A'].push_back(make_pair(a[0]-'A',i));
        deg[a[0]-'A']++,deg[a[1]-'A']++;
    }
    for(i=0;i<=25;i++)
        sort(g[i].begin(),g[i].end());
    for(i=0;i<=25;i++){
        if(deg[i]%2==1){
            st=i;
            break;
        }
        else if(deg[i]>0){
            mi=min(mi,i);
        }
    }
    if(st==-1)st=mi;
    dfs(st,0);
    return 0;
}
/*
6
AB
AE
BD
BC
CE
DE
*/
