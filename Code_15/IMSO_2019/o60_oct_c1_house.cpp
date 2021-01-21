/*
    TASK:House_ss
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200100
struct A{
    int pre,sub,sum,now;
};
int a[N];
A seg[N*4];
void build(int l,int r,int now){
    if(l==r){
        seg[now].pre=seg[now].sub=seg[now].sum=seg[now].now=a[r];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].pre=max(seg[now*2].pre,max(seg[now*2].sum,seg[now*2].sum+seg[now*2+1].pre));
    seg[now].sub=max(seg[now*2+1].sub,max(seg[now*2+1].sum,seg[now*2+1].sum+seg[now*2].sub));
    seg[now].sum=seg[now*2].sum+seg[now*2+1].sum;
    seg[now].now=max(seg[now*2].now,max(seg[now*2+1].now,max(seg[now*2].sum+seg[now*2+1].pre,max(seg[now*2+1].sum+seg[now*2].sub,seg[now*2].sub+seg[now*2+1].pre))));
}
A query(int l,int r,int a,int b,int now){
    A z;
    z.pre=z.sub=z.sum=z.now=0;
    if(r<a || l>b)return z;
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)>>1;
    A rnow,lnow;
    lnow=query(l,mid,a,b,now*2);
    rnow=query(mid+1,r,a,b,now*2+1);
    z.pre=max(lnow.pre,max(lnow.sum,lnow.sum+rnow.pre));
    z.sub=max(rnow.sub,max(rnow.sum,rnow.sum+lnow.sub));
    z.sum=lnow.sum+rnow.sum;
    z.now=max(lnow.now,max(rnow.now,max(lnow.sum+rnow.pre,max(rnow.sum+lnow.sub,lnow.sub+rnow.pre))));
    return z;
}
int main(){
    int n,m,i,j,aa,bb;
    A ans;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,n,1);
//    for(int i=1;i<=n*4;i++)printf("%d %d %d %d\n",seg[i].pre,seg[i].sub,seg[i].sum,seg[i].now);
    while(m--){
        scanf("%d %d",&aa,&bb);
        bb=min(n,bb+1);
        ans=query(1,n,aa+1,bb,1);
        ans.now=max(ans.now,0);
        printf("%d\n",ans.now);
    }
}