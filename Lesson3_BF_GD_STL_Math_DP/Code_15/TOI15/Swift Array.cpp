/*
    TASK:Swift Array
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int seg[400010];
//void build(int l,int r,int now){
//    if(l==r){
//        return seg[now]=a[l];
//    }
//    mid=(l+r)/2;
//    build(l,mid,now*2);
//    build(mid+1,r,now*2+1);
//    seg[now]=max(seg[now*2],seg[now*2+1]);
//}//build(1,n,1)
void update(int l,int r,int now,int idx,int val){
    if(l==r && l==idx){
        seg[now]=val;
        return ;
    }
    if(l>idx || r<idx) return ;
    int mid=(l+r)>>1;
    update(l,mid,now*2,idx,val);
    update(mid+1,r,now*2+1,idx,val);
    seg[now]=max(seg[now*2],seg[now*2+1]);
}
int query(int l,int r,int now,int ll,int rr){
    if(r<ll || l>rr)return -1e9;
    if(l>=ll && r<=rr) return seg[now];
    int mid=(l+r)>>1;
    return max(query(l,mid,now*2,ll,rr),query(mid+1,r,now*2+1,ll,rr));
}
int main(){
    int n,t,x,y,ans,i;
    char q;
    scanf("%d %d",&n,&t);
    //for(i=1;i<=t;i++)scanf("%c %d %d",&q,&x,&y);
    for(i=1;i<=t;i++){
        scanf(" %c %d %d",&q,&x,&y);
        if(q=='U'){
            update(1,n,1,x,y);
        }else
        if(q=='Q'){
            ans=query(1,n,1,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
