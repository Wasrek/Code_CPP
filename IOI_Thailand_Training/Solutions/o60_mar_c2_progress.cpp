/*
    TASK: o60_mar_c2_progress
    LANG: CPP
    AUTHOR: WasreK
    ALGO: segment tree
    TYPE: BATCH
    SCORE: 100
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pre,sub,sum,ma;
};
A seg[(100000*4)+10];
void update(int l,int r,int a,int v,int now){
    if(l>a || r<a) return ;
    if(l==r){
        seg[now]={v,v,v,v};
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,v,now*2);
    update(mid+1,r,a,v,now*2+1);
    A ll=seg[now*2],rr=seg[now*2+1];
    seg[now].ma=max({ll.sub+rr.pre,ll.ma,rr.ma});
    seg[now].pre=max(ll.pre,ll.sum+rr.pre);
    seg[now].sub=max(rr.sub,rr.sum+ll.sub);
    seg[now].sum=ll.sum+rr.sum;
    return ;
}
int main()
{
    int n,m,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        update(1,n,i,v,1);
    }
    printf("%d\n",seg[1].ma);
    int now;
    while(m--){
        scanf("%d %d",&now,&v);
        now++;
        update(1,n,now,v,1);
        printf("%d\n",seg[1].ma);
    }
    return 0;
}