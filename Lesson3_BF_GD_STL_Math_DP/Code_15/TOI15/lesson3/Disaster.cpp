/*
    TASK:Disaster
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,i;
    bool operator<(const A&o)const{
    return u<o.u;
    }
};
int mark[310],dg[30],ans[310],n;
vector<A> g[30];
void dfs(int u,int state){
    int i;
    ans[state]=u;
    if(state==n){
        for(i=0;i<=state;i++){
            printf("%c ",ans[i]+'A');
        }
        exit(0);
    }
    for(auto x:g[u]){
        if(mark[x.i])continue;
        mark[x.i]=1;
        dfs(x.u,state+1);
        mark[x.i]=0;
    }
}
int main(){
    int i;
    char u,v;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c %c",&u,&v);
        g[u-'A'].push_back({v-'A',i});
        g[v-'A'].push_back({u-'A',i});
        dg[u-'A']++;
        dg[v-'A']++;
    }
    for(i=0;i<26;i++)sort(g[i].begin(),g[i].end());
    int st=-1,mi=40;
    for(i=0;i<26;i++){
        if(dg[i]%2==1){
            st=i;
            break;
        }else if(dg[i]>0)mi=min(mi,i);
    }
    if(st==-1)st=mi;
    dfs(st,0);
    return 0;
}
