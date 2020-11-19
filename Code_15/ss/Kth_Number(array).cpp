/*
    TASK:Kth_Number
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#define N 500003
#define lgn 20
using namespace std;
int L[N*lgn], R[N*lgn], sum[N*lgn];
int sz;//how many node you had builded
int root[N];
int Copy(int u,int &v){
    ++sz;
    L[sz] = L[u];
    R[sz] = R[u];
    sum[sz] = sum[u];
    return v = sz;
}
void upd(int p,int idx,int l,int r){//  p = now idx = target we want to update l and r are range
    if(l==r){sum[p] = 1;return ;}//leaf
    int mid = (l+r)>>1;
    if(idx <= mid) upd(Copy(L[p],L[p]),idx,l,mid);
    else upd(Copy(R[p],R[p]),idx,mid+1,r);
    sum[p]=sum[L[p]]+sum[R[p]];//update the now
}
int query(int p,int q,int k,int l,int r,int SUM){//p is the pointer that point 1-(l-1) tree ans, in the same way q for the 1-r tree
    // l - r is the range that the question ask
    //p = 1 to l-1
    //r = 1 to r
    //q-p = l-r
    if(l==r) return l;
    int mid = (l+r)>>1;
    if(sum[L[q]] - sum[L[p]]+SUM >=k)return query(L[p],L[q],k,l,mid,SUM);
    return query(R[p],R[q],k,mid+1,r,SUM+sum[L[q]]-sum[L[p]]);
}
int main(){
    int i,n,q,l,r,k,a;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        Copy(root[i-1],root[i]);
        upd(root[i],a,1,n);
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&k);
        printf("%d\n",query(root[l-1],root[r],k,1,n,0));
    }
    return 0;
}
