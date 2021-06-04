#include<bits/stdc++.h>
using namespace std;
long long col[100010],ans[100010],mxsz[100010],sz[100010];
unordered_map<long long,long long> mp[100010];
unordered_map<long long,long long> ::iterator  it;
vector<long long> g[100010];
void dfs(long long i,long long p){
    long long mx=-1,d;
    sz[i]=1;
    for(auto x : g[i]){
        if(x==p) continue;
        dfs(x,i);
        sz[i]+=sz[x];
        if(mx<sz[x]) mx=sz[x],d=x;
    }
    if(mx==-1){
        mp[i][col[i]]=1;
        mxsz[i]=1;
        ans[i]=col[i];
        return ;
    }
    swap(mp[d],mp[i]);
    mxsz[i]=mxsz[d];
    ans[i]=ans[d];
    mp[i][col[i]]++;
    if(mp[i][col[i]]==mxsz[i]){
        ans[i]+=col[i];
    }
    if(mp[i][col[i]]>mxsz[i]){
        mxsz[i]=mp[i][col[i]];
        ans[i]=col[i];
    }
    for(auto x : g[i]){
        if(x==p||x==d) continue;
        for(it=mp[x].begin();it!=mp[x].end();it++){
            mp[i][it->first]+=(it->second);
            if(mp[i][it->first]==mxsz[i]){
                ans[i]+=it->first;
            }
            if(mp[i][it->first]>mxsz[i]){
                mxsz[i]=mp[i][it->first];
                ans[i]=it->first;
            }
        }
    }
}
int main(){
    long long i,n,u,v;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&col[i]);
    }
    for(i=0;i<n-1;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    for(i=1;i<=n;i++) printf("%lld ",ans[i]);
return 0;
}
