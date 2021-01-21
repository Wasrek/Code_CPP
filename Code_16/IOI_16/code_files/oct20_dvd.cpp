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
    int ma,mi;
};
A seg[N*4];
int v[N];
void build(int l,int r,int now){
    if(l==r){
        seg[now].ma=seg[now].mi=l;
        v[l]=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].ma=max(seg[now*2].ma,seg[now*2+1].ma);
    seg[now].mi=min(seg[now*2].mi,seg[now*2+1].mi);
    return ;
}
void update(int l,int r,int a,int v,int now){
    if(l>a || r<a) return ;
    if(l==r){
        seg[now].ma=seg[now].mi=v;
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,v,now*2);
    update(mid+1,r,a,v,now*2+1);
    seg[now].ma=max(seg[now*2].ma,seg[now*2+1].ma);
    seg[now].mi=min(seg[now*2].mi,seg[now*2+1].mi);
    return ;
}
A query(int l,int r,int a,int b,int now){
    // printf("%d %d\n",l,r);
    A k,ll,rr;
    k.ma=-1;k.mi=1e9;
    if(l>b || r<a) return k;
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)>>1;
    ll=query(l,mid,a,b,now*2);
    rr=query(mid+1,r,a,b,now*2+1);
    k.ma=max(ll.ma,rr.ma);
    k.mi=min(ll.mi,rr.mi);
    // printf("- %d %d\n",k.ma,k.mi);
    return k;
}
int main()
{
    int q,n,k,opr,a,b;
    A ans;
    scanf("%d %d",&n,&k);
    build(1,n,1);
    while(k--){
        scanf("%d %d %d",&opr,&a,&b);
        a++,b++;
        if(!opr){
            update(1,n,a,v[b],1);
            update(1,n,b,v[a],1);
            swap(v[a],v[b]);
        }else{
            ans=query(1,n,a,b,1);
            // printf("%d %d\n",ans.mi,ans.ma);
            if(ans.mi==a && ans.ma==b){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}