/*
    TASK:Love letter
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
char a[N];
struct A{
    long long l,o,v,e,lo,lov,ov,love,ve,ove;
};
A seg[4*N];
void build(int l,int r,int now){
    if(l==r){
        seg[now].l=seg[now].o=seg[now].v=seg[now].e=seg[now].lo=seg[now].lov=seg[now].ov=seg[now].ove=seg[now].ve=seg[now].love=0;
        if(a[l]=='L')seg[now].l++;
        if(a[l]=='O')seg[now].o++;
        if(a[l]=='V')seg[now].v++;
        if(a[l]=='E')seg[now].e++;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].l=seg[now*2].l+seg[now*2+1].l;
    seg[now].v=seg[now*2].v+seg[now*2+1].v;
    seg[now].e=seg[now*2].e+seg[now*2+1].e;
    seg[now].o=seg[now*2].o+seg[now*2+1].o;
    seg[now].lo=seg[now*2].lo+seg[now*2+1].lo+(seg[now*2].l*seg[now*2+1].o);
    seg[now].ov=seg[now*2].ov+seg[now*2+1].ov+(seg[now*2].o*seg[now*2+1].v);
    seg[now].ve=seg[now*2].ve+seg[now*2+1].ve+(seg[now*2].v*seg[now*2+1].e);
    seg[now].lov=seg[now*2].lov+seg[now*2+1].lov+seg[now*2].l*seg[now*2+1].ov+seg[now*2].lo*seg[now*2+1].v;
    seg[now].ove=seg[now*2].ove+seg[now*2+1].ove+seg[now*2].o*seg[now*2+1].ve+seg[now*2].ov*seg[now*2+1].e;
    seg[now].love=seg[now*2].love+seg[now*2+1].love+seg[now*2].lo*seg[now*2+1].ve+seg[now*2].l*seg[now*2+1].ove+seg[now*2].lov*seg[now*2+1].e;
}
A query(int l,int r,int a,int b,int now){
    A n;
    n.l=n.o=n.v=n.e=n.lo=n.ov=n.ve=n.lov=n.ove=n.love=0ll;
    if(l>b || r<a) return n;
    if(l>=a && r<=b)return seg[now];
    int mid=(l+r)>>1;
    A ll=query(l,mid,a,b,now*2);
    A rr=query(mid+1,r,a,b,now*2+1);
    n.l=ll.l+rr.l;
    n.v=ll.v+rr.v;
    n.e=ll.e+rr.e;
    n.o=ll.o+rr.o;
    n.lo=ll.lo+rr.lo+(ll.l*rr.o);
    n.ov=ll.ov+rr.ov+(ll.o*rr.v);
    n.ve=ll.ve+rr.ve+(ll.v*rr.e);
    n.lov=ll.lov+rr.lov+ll.l*rr.ov+ll.lo*rr.v;
    n.ove=ll.ove+rr.ove+ll.o*rr.ve+ll.ov*rr.e;
    n.love=ll.love+rr.love+ll.lo*rr.ve+ll.l*rr.ove+ll.lov*rr.e;
    return n;
}
int main()
{
    int n,q;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&a[i]);
    }
    build(1,n,1);
    long long a,b;
    A ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&a,&b);
        ans=query(1,n,a,b,1);
        printf("%lld\n",ans.love);
    }
    return 0;
}
