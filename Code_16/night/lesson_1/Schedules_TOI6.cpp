/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct H{
    int n;
    bool operator< (const H & o) const{
        return n>o.n;
    }
};
int ans[500100],la[500100];
map<int,int> mp;
vector< int > g;
priority_queue< H > h;
int main()
{
    int n,m,k,s,e;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=k;i++){
        h.push({0});
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d",&s,&e);
        mp[s]=i;
        la[s]=e;
        g.push_back(s);
    }
    sort(g.begin(),g.end());
    for(auto x: g){
        // printf("%d %d\n",x,la[x]);
        // printf("%d\n",h.top().n);
        if(!h.empty() && h.top().n<x){
            ans[mp[x]]=1;
            h.pop();
            h.push({la[x]});
        }else{
            ans[mp[x]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&k);
        if(ans[k]){
            printf("Y ");
        }else printf("N ");
    }
    return 0;
}