/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,t,n;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
vector< A > g;
vector< int > ans1,ans2;
int ma[100100],p[100100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,k,u,v,w,ha,tu,tv,tw;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        h.push({u,v,w,0,i});
    }
    int cnt=0;
    for(int i=1;i<=k;i++){
        scanf("%d %d",&u,&v);
        if(!ma[u]){
            ma[u]=1;
            cnt++;
        }
        g.push_back({u,v,0,1,i});
    }
    ha=n-cnt;
    cnt=0;
    while(!h.empty()){
        if(cnt>=ha) break;
        tu=h.top().u;
        tv=h.top().v;
        tw=h.top().w;
        printf("%d %d %d\n",tu,tv,tw);
        if(fin(tu)!=fin(tv)){
            p[fin(tu)]=fin(tv);
            ans1.push_back(h.top().n);
            if(ma[tu]!=2){
                ma[tu]=2;
                cnt++;
            }
            if(ma[tv]!=2){
                ma[tv]=2;
                cnt++;
            }
        }
        h.pop();
    }
    printf("%d %d\n",cnt,ha);
    for(auto x:ans1){
        printf("%d\n",x);
    }
    return 0;
}