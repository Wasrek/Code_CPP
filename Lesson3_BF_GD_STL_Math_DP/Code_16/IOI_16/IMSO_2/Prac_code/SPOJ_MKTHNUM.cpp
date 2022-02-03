/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct A{
    int cnt,l,r;
}seg[24*N];//4*N + ((N version)*logN)
int arr[N],sot[N],idx=0,root[N];
unordered_map< int,int > mp;
void build(int l,int r,int &now){
    now=++idx;
    if(l==r){
        seg[now].cnt=0;
        seg[now].l=seg[now].r=-1;
        return ;
    }
    int mid=(l+r)>>1,L,R;
    build(l,mid,L);
    build(mid+1,r,R);
    seg[now]={0,L,R};
    return ;
}
void update(int l,int r,int &now,int last,int upd){
    now=last;
    if(upd<l || upd>r) return ;
    now=++idx;
    seg[now]=seg[last];
    if(l==r){
        seg[now].cnt=1;
        return ;
    }
    int mid=(l+r)>>1,L,R;
    update(l,mid,L,seg[now].l,upd);
    update(mid+1,r,R,seg[now].r,upd);
    seg[now]={seg[L].cnt+seg[R].cnt,L,R};
    return ;
}
int que(int l,int r,int a,int b,int k){
    if(l==r){
        return sot[l];
    }
    int mid=(l+r)>>1;
    int cntlef=seg[seg[b].l].cnt-seg[seg[a].l].cnt;
    if(k<=cntlef){
        return que(l,mid,seg[a].l,seg[b].l,k);
    }else return que(mid+1,r,seg[a].r,seg[b].r,k-cntlef);
}
int main()
{
    int n,m,a,b,k;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        sot[i]=arr[i];
    }
    sort(sot+1,sot+1+n);
    for(int i=1;i<=n;i++){
        mp[sot[i]]=i;
    }
    build(1,n,root[0]);
    for(int i=1;i<=n;i++){
        update(1,n,root[i],root[i-1],mp[arr[i]]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&k);
        printf("%d\n",que(1,n,root[a-1],root[b],k));
    }
    return 0;
}