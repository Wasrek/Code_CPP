#include<bits/stdc++.h>
using namespace std;
#define N 100100
int seg[4*N],lazy[4*N],a[N];
void build(int l,int r,int now){
    if(l==r){
        seg[now]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now]=max(seg[now*2],seg[now*2+1]);
}
void update(int l,int r,int a,int b,int now){
    if(lazy[now]){
        seg[now]=(r-l+1)-seg[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        lazy[now]=0;
    }
    if(l>b || r<a)return ;
    if(l>=a && r<=b){
        seg[now]=(r-l+1)-seg[now];
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2);
    update(mid+1,r,a,b,now*2+1);
    seg[now]=seg[now*2]+seg[now*2+1];
}
int query(int l,int r,int a,int b,int now){
    if(lazy[now]){
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        seg[now]=(r-l+1)-seg[now];
        seg[now]=0;
    }
    if(l>b || r<a)return 0;
    if(l<=b && r>=a){
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
        return seg[now];
    }
    int mid=(l+r)>>1;
    return query(l,mid,a,b,now*2)+query(mid+1,r,a,b,now*2+1);
}
int main(){

}
