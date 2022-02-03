#include<bits/stdc++.h>
using namespace std;
char a[100010];
long long w[100010],p[100010],q[100010],cntp[200010],cntq[200010];
vector<long long> g[100010];
void dfs1(long long n,long long pa){
    for(auto x : g[n]){
        if(pa==x) continue;
        p[x]=p[n]+w[x];
        if(p[x]<100000) continue;
        cntp[p[x]]++;
        dfs1(x,n);
    }
}
void dfs2(long long n,long long pa){
    for(auto x : g[n]){
        if(pa==x) continue;
        q[x]=q[n]+w[x];
        if(q[x]>100000) continue;
        cntq[q[x]]++;
        dfs2(x,n);
    }
}
int main(){
    long long i,j,n,s,t,u,v;
    char a[100010];
    scanf("%lld %lld %lld",&n,&s,&t);
    for(i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf(" %s",a);
    for(i=0;i<n;i++){
        if(a[i]=='(') w[i+1]=1;
        else w[i+1]=-1;
    }
    p[s]=100000+w[s];
    q[t]=100000+w[t];
    cntp[p[s]]++;
    cntq[q[t]]++;
    dfs1(s,-1);
    dfs2(t,-1);
    long long ans=0;
    for(i=0;i<=200000;i++){
        ans=ans+(cntp[i]*cntq[200000-i]);
    }
    printf("%lld",ans);
return 0;
}
