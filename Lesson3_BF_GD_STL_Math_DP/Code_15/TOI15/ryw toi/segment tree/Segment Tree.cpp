/*
    TASK:Segment Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
int seg[4*N];
void update(int l,int r,int a,int b,int now){
    if(l>a || r<a)return ;
    if(l==r){
        seg[now]=b; return ;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,now*2);
    update(mid+1,r,a,b,now*2+1);
    seg[now]=max(seg[now*2],seg[now*2+1]);
}
int query(int l,int r,int a,int b,int now){
    if(r<a || l>b) return -1e9;
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)/2;
    return max(query(l,mid,a,b,now*2),query(mid+1,r,a,b,now*2+1));
}
int main(){
    int n,q,a,b;
    char opr;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        if(opr=='U'){
            update(1,n,a,b,1);
        }else{
        printf("%d\n",query(1,n,a,b,1));
        }
    }
    return 0;
}
