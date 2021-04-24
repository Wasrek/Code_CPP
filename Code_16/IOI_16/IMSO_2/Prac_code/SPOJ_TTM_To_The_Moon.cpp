/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N (int)(1e5)+10
#define LOGN 15
typedef long long ll;
struct A{
    ll sum,lz;
    int l,r;
} seg[15000000];
int a[N],ver=0,root[N*2],idx=0;
void build(int l,int r,int &now){
    now=++idx;
    if(l==r){
        seg[now]={a[l],0,-1,-1};
        return ;
    }
    int mid=(l+r)>>1,L,R;
    build(l,mid,L);
    build(mid+1,r,R);
    seg[now]={seg[L].sum+seg[R].sum,0,L,R};
    return ;
}
void upd_lz(int now,int l,int r){
    if(!seg[now].lz) return ;
    seg[now].sum+=(r-l+1)*seg[now].lz;
    if(l!=r){
        seg[++idx]=seg[seg[now].l];
        seg[idx].lz+=seg[now].lz;
        seg[now].l=idx;
        seg[++idx]=seg[seg[now].r];
        seg[idx].lz+=seg[now].lz;
        seg[now].r=idx;
    }
    seg[now].lz=0;
    return ;
}
void upd(int l,int r,int now,int a,int b,int v,int &node){
    upd_lz(now,l,r);
    node=now;
    if(b<l || r<a) return ;
    node=++idx;
    seg[node]=seg[now];
    if(l>=a && r<=b){
        seg[node].lz+=v;
        upd_lz(node,l,r);
        return ;
    }
    int L,R,mid=(l+r)>>1;
    upd(l,mid,seg[node].l,a,b,v,L);
    upd(mid+1,r,seg[now].r,a,b,v,R);
    seg[node]={seg[L].sum+seg[R].sum,0,L,R};
    return ;
}
ll que(int l,int r,int now,int a,int b){
    upd_lz(now,l,r);
    if(b<l || r<a) return 0;
    if(l>=a && r<=b) return seg[now].sum;
    int mid=(l+r)>>1;
    ll lef=que(l,mid,seg[now].l,a,b);
    ll rig=que(mid+1,r,seg[now].r,a,b);
    return lef+rig;
}
int main()
{
    int n,q,l,r,d;
    char c;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,n,root[0]);
    for(int i=1;i<=q;i++){
        scanf(" %c",&c);
        if(c=='C'){
            scanf("%d %d %d",&l,&r,&d);
            upd(1,n,root[ver],l,r,d,root[ver+1]);
            ver++;
        }else if(c=='Q'){
            scanf("%d %d",&l,&r);
            printf("%lld\n",que(1,n,root[ver],l,r));
        }else if(c=='H'){
            scanf("%d %d %d",&l,&r,&d);
            printf("%lld\n",que(1,n,root[d],l,r));
        }else{
            scanf("%d",&ver);
        }
    }
    return 0;
}