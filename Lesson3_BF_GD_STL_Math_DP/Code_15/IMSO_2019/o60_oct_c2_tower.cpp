/*
    TASK:tower
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200010
struct A{
    int l,r,ma,v;
};
struct B{
    int mark,v;
};
A seg[4*N];
B lazy[4*N];
void build(int l,int r,int now){
    if(l==r){
        seg[now].v=0;
        seg[now].ma=1;
        seg[now].l=seg[now].r=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].l=0;
    seg[now].r=0;
    seg[now].ma=1;
    seg[now].v=0;
}
void update(int l,int r,int a,int b,int now,int v){
    // cout << l << ' ' << r << ' ' << now << endl;
    if(lazy[now].mark){
        seg[now].l+=lazy[now].v;
        seg[now].r+=lazy[now].v;
        seg[now].v+=lazy[now].v;
        if(l!=r){
        lazy[now*2].mark=1;
        lazy[now*2].v+=lazy[now].v;
        lazy[now*2+1].mark=1;
        lazy[now*2+1].v+=lazy[now].v;
        }
        lazy[now].mark=0;
        lazy[now].v=0;
    }
    if(l>b || r<a) return ;
    if(l>=a && r<=b){
        seg[now].l+=v;
        seg[now].r+=v;
        seg[now].v+=v;
        if(l!=r){
        lazy[now*2].mark=1;
        lazy[now*2].v+=v;
        lazy[now*2+1].mark=1;
        lazy[now*2+1].v+=v;
        }
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2,v);
    update(mid+1,r,a,b,now*2+1,v);
    seg[now].l=seg[now*2].l;
    seg[now].r=seg[now*2+1].r;
    if(seg[now*2].v>seg[now*2+1].v){
        seg[now].v=seg[now*2].v;
        seg[now].ma=seg[now*2].ma;
    }else
    if(seg[now*2+1].v>seg[now*2].v){
        seg[now].v=seg[now*2+1].v;
        seg[now].ma=seg[now*2+1].ma;
    }else{
        seg[now].v=seg[now*2].v;
        if(seg[now*2].r==seg[now*2+1].l && seg[now*2].r==seg[now*2].v){
            seg[now].ma=seg[now*2].ma+seg[now*2+1].ma-1;
        }else{
            seg[now].ma=seg[now*2].ma+seg[now*2+1].ma;
        }
    }
}

int main(){
    int n,m,a,b,x;
    scanf("%d %d",&n,&m);
    build(1,n,1);
    while(m--){
        scanf("%d %d %d",&a,&b,&x);
        update(1,n,a,b,1,x);
//        printf("\n");
//        for(int i=1;i<=n*4;i++){
//            printf("%d %d\n",seg[i].v,seg[i].ma);
//        }
//        printf("\n");
        printf("%d %d\n",seg[1].v,seg[1].ma);
    }
}