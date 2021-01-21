/*
    TASK:highway
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int now,tim;
    bool operator<(const A&o) const{
        return tim > o.tim;
    }
};
priority_queue< A > h;
vector< int > g[100010],gt[100010];
int out[200100],qu[200100],tq[200100],mark[100100],first[100100],sec[100100];
int main()
{
    int n,m,q,a,b,op;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    int cnt1=1,cnt2=0;
    for(int i=1;i<=q;i++){
        scanf("%d %d",&op,&a);
        if(op==1){
            out[a]=cnt1++;
        }else{
            tq[++cnt2]=cnt1-1;
            qu[cnt2]=a;
        }
    }
    if(out[1]){
        h.push({1,out[1]});
    }else h.push({1,(int)1e9});
    int tn,tt;
    while(!h.empty()){
        tn=h.top().now;
        tt=h.top().tim;
        h.pop();
        if(first[tn])continue;
        first[tn]=tt;
        for(auto x: g[tn]){
            if(mark[x] || first[x])continue;
            if(out[x]){
                h.push({x,min(out[x],tt)});
            }else{
                h.push({x,tt});
            }
            mark[x]++;
        }
    }
    memset(mark,0,sizeof mark);
    h.push({n,first[n]});
    while(!h.empty()){
        tn=h.top().now;
        tt=h.top().tim;
        h.pop();
        if(sec[tn])continue;
        sec[tn]=tt;
        for(auto x: gt[tn]){
            if(mark[x] || sec[x])continue;
            h.push({x,min(first[x],tt)});
            mark[x]++;
        }
    }
    for(int i=1;i<=cnt2;i++){
        if(sec[qu[i]]<=tq[i]){
            printf("0\n");
        }else
        {
            printf("1\n");
        }

    }
    return 0;
}
