/*
    TASK:Progress
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
struct A{
    int pre,sub,sum,ma;
};
A seg[4*N];
int a[N];
void build(int l,int r,int now){
    if(l==r){
        seg[now].pre=seg[now].sub=seg[now].sum=seg[now].ma=a[l];
        seg[now].ma=max(seg[now].ma,0);
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].pre=max(seg[now*2].pre,max(seg[now*2].sum,seg[now*2].sum+seg[now*2+1].pre));
    seg[now].sub=max(seg[now*2+1].sub,max(seg[now*2+1].sum,seg[now*2].sub+seg[now*2+1].sum));
    seg[now].sum=seg[now*2].sum+seg[now*2+1].sum;
    seg[now].ma=max(seg[now*2].ma,max(seg[now*2+1].ma,max(seg[now].pre,max(seg[now].sub,seg[now*2].sub+seg[now*2+1].pre))));
}
void update(int l,int r,int a,int v,int now){
    if(l>a || r<a) return ;
    if(l==r){
        seg[now].pre=seg[now].sub=seg[now].sum=seg[now].ma=v;
        seg[now].ma=max(0,seg[now].ma);
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,v,now*2);
    update(mid+1,r,a,v,now*2+1);
    seg[now].pre=max(seg[now*2].pre,max(seg[now*2].sum,seg[now*2].sum+seg[now*2+1].pre));
    seg[now].sub=max(seg[now*2+1].sub,max(seg[now*2+1].sum,seg[now*2].sub+seg[now*2+1].sum));
    seg[now].sum=seg[now*2].sum+seg[now*2+1].sum;
    seg[now].ma=max(seg[now*2].ma,max(seg[now*2+1].ma,max(seg[now].pre,max(seg[now].sub,seg[now*2].sub+seg[now*2+1].pre))));
}
int main(){
    int n,m,b,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,n,1);
     printf("%d\n",seg[1].ma);
    while(m--){
        scanf("%d %d",&b,&v);
        b++;
        update(1,n,b,v,1);
        printf("%d\n",seg[1].ma);
    }
}