/*
    TASK:Places Sacred
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
    bool operator<(const A&o) const{
    return w < o.w;
    }
};
priority_queue< A > he;
vector< A > g[200100];
long long mark[200100];
int main(){
    long long n,m,u,v,w,ans=0;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w-1});
        g[v].push_back({u,w-1});
    }
    he.push({1,0});
    while(!he.empty()){
        u=he.top().v,w=he.top().w,he.pop();
        if(mark[u]) continue;
        mark[u]=1;
        ans+=w;
        for(auto x:g[u]){
            if(mark[x.v]) continue;
            he.push({x.v,x.w});
        }
    }
    printf("%lld\n",ans);
}
/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/
