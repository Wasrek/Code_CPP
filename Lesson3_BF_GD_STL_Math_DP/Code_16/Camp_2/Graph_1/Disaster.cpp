/*
    TASK:Disaster
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
    bool operator <(const A & o) const{
        return v<o.v;
    }
};
char s[5];
int n,deg[40],ans[400],mark[330];
vector< A > g[40];
void dfs(int now,int state){
    ans[state]=now;
    if(state==n){
        for(int i=0;i<=n;i++){
            printf("%c ",ans[i]+'A');
        }
        exit(0);
    }
    for(auto x: g[now]){
        if(mark[x.i]) continue;
        mark[x.i]=1;
        dfs(x.v,state+1);
        mark[x.i]=0;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",s);
        g[s[0]-'A'].push_back({i,s[1]-'A'});
        g[s[1]-'A'].push_back({i,s[0]-'A'});
        deg[s[0]-'A']++;
        deg[s[1]-'A']++;
    }
    for(int i=0;i<'Z'-'A';i++) sort(g[i].begin(),g[i].end());
    int st=-1,mi=50;
    for(int i=0;i<='Z'-'A';i++){
        if(deg[i]%2){
            st=i;
            break;
        }else if(deg[i]>0) mi=min(mi,i);
    }
    if(st==-1)st=mi;
    dfs(st,0);
    return 0;
}