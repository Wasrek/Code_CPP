/*
    TASK:Segment Tree
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int seg[400010];
void update(int l,int r,int a,int b,int idx){
    if(l>a || r<a)return ;
    if(l==r){
        seg[idx]=b;
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,idx*2);
    update(mid+1,r,a,b,idx*2+1);
    seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}
int query(int l,int r,int a,int b,int idx){
    if(l>b || r<a)return -1e9;
    if(l>=a && r<=b){
        return seg[idx];
    }
    int mid=(l+r)>>1;
    return max(query(l,mid,a,b,idx*2),query(mid+1,r,a,b,idx*2+1));
}
int main(){
    int n,q,a,b;
    char f;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf(" %c %d %d",&f,&a,&b);
        if(f=='U'){
            update(1,n,a,b,1);
        }else{
            printf("%d\n",query(1,n,a,b,1));
        }
    }
}
/*
5 4
U 1 -14
U 1 -1
P 2 2
P 3 5

6 7
U 5 280
U 1 7
P 1 2
P 3 5
U 4 -8654578
*/
