/*
    TASK:Sagittarius A
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w,i;
    bool operator<(const A& o)const{
        return w<o.w;
    }
};
long long p[100010],mark[100010];
priority_queue< A >h;
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
vector<long long> g;
int main(){
    long long n,m,i,j,u,v,w,t,coun=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        h.push({u,v,w,i});
    }
    scanf("%lld",&t);
    long long ch=0,ans=0;
    while(!h.empty()){
        u=h.top().u;
        v=h.top().v;
        w=h.top().w;
        i=h.top().i;
        h.pop();
        u=fin(u);
        v=fin(v);
        if(u!=v){
            p[u]=v;
            ans+=w;
            g.push_back(i);
            coun++;
        }else{
        if(!ch){
            ans+=w;
            ch=1;
            g.push_back(i);
            coun++;
        }
        }
    }
    if(coun!=n){
        printf("-1\n");
        return 0;
    }
    int cou=0,pi;
    for(i=1;i<=n;i++){
        pi=fin(i);
        //printf("%d ",pi);
        if(!mark[pi]){
            cou++;
            mark[pi]=1;
        }
        if(cou>1){
            printf("-1\n");
            return 0;
        }
    }
    sort(g.begin(),g.end());
    printf("%lld\n",ans);
    if(t==2){
        for(auto x:g){
            printf("%lld ",x);
        }
    }
    printf("\n");
    return 0;
}
