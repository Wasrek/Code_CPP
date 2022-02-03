/*
    TASK:Bie's Wedding
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,w;
    bool operator < (const A & o) const{
        if(w!=o.w)return w>o.w;
        return i>o.i;
    }
};
vector< A > g[100];
long long dis[100];
priority_queue< A > h;
int main()
{
    long long m,w;
    char a,b;
    scanf("%lld",&m);
    while(m--){
        scanf(" %c %c %lld",&a,&b,&w);
        g[a-'A'].push_back({b-'A',w});
        g[b-'A'].push_back({a-'A',w});
    }
    for(int i=0;i<='z'-'A';i++){
        dis[i]=1<<30;
    }
    dis['Z'-'A']=0;
    h.push({'Z'-'A',0});
    long long i;
    while(!h.empty()){
        i=h.top().i;
        w=h.top().w;
        h.pop();
        if(i>=0 && i<='Y'-'A'){
            printf("%c %lld\n",'A'+i,w);
            return 0;
        }
        for(auto x: g[i]){
            if(dis[x.i]<=w+x.w) continue;
            dis[x.i]=w+x.w;
            h.push({x.i,x.w+w});
        }
    }
    return 0;
}