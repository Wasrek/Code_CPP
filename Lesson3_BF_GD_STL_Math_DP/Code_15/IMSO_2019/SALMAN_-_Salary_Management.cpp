/*
    TASK:SALMAN - Salary Management
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
struct A{
    int mi,sum;
};
A seg[4*N];
int lazy[4*N];
vector < int > g[N];
int sa[N],st[N*2],cnt=0;
vector< int > wh[N];
void dfs(int i){
    st[++cnt]=i;
    for(auto x: g[i]){
        dfs(x);
        st[++cnt]=x;
    }
    return ;
}
void build(int l,int r,int now){
    if(l==r){
        seg[now].mi=seg[now].sum=sa[st[l]];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].mi=min(seg[now*2].mi,seg[now*2+1].mi);
    seg[now].sum=seg[now*2].sum+seg[now*2+1].sum;
    return ;
}
void update(int l,int r,int a,int b,int now,int v){
    if(l>b || r<a) return ;
    if(l>=a && r<=b){
        seg[now].mi+=v;
        seg[now].sum+=(l-r+1)*v;
        if(l!=r){
            lazy[now*2]=v;
            lazy[now*2+1]=v;
        }
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2,v);
    update(mid+1,r,a,b,now*2+1,v);
    seg[now].mi=min(seg[now*2].mi,seg[now*2+1].mi);
    seg[now].sum=seg[now*2].sum+seg[now*2+1].sum;
}
A query(int l,int r,int a,int b,int now){
    A z;
    z.mi=z.sum=0;
    if(l>b || r<a) return z;
    if(lazy[now]){
        seg[now].mi+=lazy[now];
        seg[now].sum+=(l-r+1)*lazy[now];
        if(l!=r){
            lazy[now*2]=lazy[now*2+1]=lazy[now];
        }
        lazy[now]=0;
    }
    if(l>=a && r<=b){
        return seg[now];
    }
    int mid=(l+r)>>1;
    A ll=query(l,mid,a,b,now*2);
    A rr=query(mid+1,r,a,b,now*2+1);
    z.mi=min(ll.mi,rr.mi);
    z.sum=ll.sum+rr.sum;
    return z;
}
int main()
{
    int q,p,opr,id;
    scanf("%d",&q);
    while(q--){
        int n,m,p;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p,&sa[i]);
            g[p].push_back(i);
        }
        dfs(1);
        st[++cnt]=1;
        for(int i=1;i<=cnt;i++){
            wh[st[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            scanf("%d %d",&opr,&id);
            if(opr==1){
                
            }else{

            }
        }
    }
    return 0;
}