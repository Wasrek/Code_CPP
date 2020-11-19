/*
    TASK:Swift Virus
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,lv,v;
};
long long v[100010],ma[100010];
vector<long long>g[100010];
vector<long long> l[100010];
queue< A >q;
priority_queue<long long> h;
int main(){
    long long n,m,k,i,a,b,u,va,lv,ans=0,maxx=0;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&v[i]);
    }
    while(m--){
        scanf("%lld %lld",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    q.push({k,0,0});ma[k]=1;
    while(!q.empty()){
        u=q.front().u;
        lv=q.front().lv;
        va=q.front().v;
        q.pop();
        l[lv].push_back(va);
        maxx=max(maxx,lv);
        for(auto x:g[u]){
            if(!ma[x]){
            q.push({x,lv+1,v[x]});
            ma[x]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(!ma[i]){
            if(v[i]>0)ans+=v[i];
        }
    }
    while(maxx){
        for(auto x:l[maxx]){
            if(x>0)
            h.push(x);
        }
        if(!h.empty()){
            ans+=h.top();
            h.pop();
        }
        maxx--;
    }
    printf("%lld\n",ans);
}
