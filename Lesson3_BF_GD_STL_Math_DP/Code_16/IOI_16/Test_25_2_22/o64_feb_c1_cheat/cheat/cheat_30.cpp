#include "cheat.h"
#include<bits/stdc++.h>
using namespace std;
struct A{
  int a,b,t;
};
struct B{
    int v,t;
};
int p[200010],lev[200010],ti=0,ch=0;
B pa[200010][25];
vector< int >n;
vector< B > g[200010];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
void cheat(int p1, int p2)
{
    ++ti;
    if(!p[p1]) p[p1]=p1,n.push_back(p1);
    if(!p[p2]) p[p2]=p2,n.push_back(p2);
    if(fin(p1)==fin(p2)) return;
    p[fin(p1)]=fin(p2);
    g[p1].push_back({p2,ti});
    g[p2].push_back({p1,ti});
}
void dfs(int i,int lv){
    // printf("%d %d %d %d\n",i,lv,pa[i][0].v,pa[i][0].t);
    lev[i]=lv;
    for(auto x: g[i]){
        if(lev[x.v]) continue;
        pa[x.v][0].v=i;
        pa[x.v][0].t=x.t;
        dfs(x.v,lv+1);
    }
}
int investigate(int p1, int p2)
{
    int ma=0;
    if(!ch){
        ch=1;
        dfs(n[0],1);
        for(int i=1;i<20;i++){
            for(auto x: n){
                pa[x][i].v=pa[pa[x][i-1].v][i-1].v;
                pa[x][i].t=max(pa[pa[x][i-1].v][i-1].t,pa[x][i-1].t);
                // printf(" (%d %d %d   %d %d) ",x,pa[x][i].v,pa[x][i].t,pa[x][i-1].v,pa[pa[x][i-1].v][i-1].v);
            }
            // printf("\n");
        }
    }
    if(!p[p1] || !p[p2] || fin(p1)!=fin(p2)) return -1;
    if(lev[p1]<lev[p2]) swap(p1,p2);
    // printf("%d %d\n",lev[p1],lev[p2]);
    for(int i=19;i>=0;i--){
        if(lev[pa[p1][i].v]>=lev[p2] && lev[pa[p1][i].v]!=0) ma=max(ma,pa[p1][i].t),p1=pa[p1][i].v;
    }
    // printf("%d %d\n",lev[p1],lev[p2]);
    for(int i=19;i>=0;i--){
        if(lev[pa[p1][i].v]!=lev[pa[p2][i].v]){
            p1=pa[p1][i].v;
            p2=pa[p2][i].v;
            ma=max(ma,max(pa[p1][i].t,pa[p2][i].t));
        }
    }
    return ma;
}