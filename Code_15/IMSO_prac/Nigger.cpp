/*
    TASK:Nigger
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
int seg[4*N],lazy[4*N];
void update(int l,int r,int a,int b,int idx){
    if(lazy[idx]){
        if(l!=r)lazy[idx*2]^=1,lazy[idx*2+1]^=1;
        seg[idx]=(r-l+1)-seg[idx];
        lazy[idx]=0;
    }
    if(l>b || r<a)return ;
    if(l>=a && r<=b){
        seg[idx]=(r-l+1)-seg[idx];
        if(l!=r)lazy[idx*2]^=1,lazy[idx*2+1]^=1;
        return ;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,idx*2);
    update(mid+1,r,a,b,idx*2+1);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int query(int l,int r,int a,int b,int idx){
    if(lazy[idx]){
        if(l!=r) lazy[idx*2]^=1,lazy[idx*2+1]^=1;
        seg[idx]=(r-l+1)-seg[idx];
        lazy[idx]=0;
    }
    if(l>b || r<a) return 0;
    if(l>=a && r<=b){
        return seg[idx];
    }
    int mid=(l+r)/2;
    return query(l,mid,a,b,idx*2)+query(mid+1,r,a,b,idx*2+1);
}
int main(){
    int n,m,opr,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&opr,&a,&b);
        if(opr==0)
            update(1,n,a,b,1);
        else
            printf("%d\n",query(1,n,a,b,1));
    }
    return 0;
}
