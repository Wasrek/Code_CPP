/*
    TASK:DVDs
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
struct A
{
    int ma,mi;
};
A seg[N*4];
int arr[N];
void build(int l,int r,int now)
{
    if(l==r)
    {
        seg[now].ma=seg[now].mi=l;
//        printf("- %d %d\n",l,now);
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].ma=max(seg[now*2].ma,seg[now*2+1].ma);
    seg[now].mi=min(seg[now*2].mi,seg[now*2+1].mi);
}
void update(int l,int r,int a,int now,int v)
{
    if(l>a || r<a)
        return ;
    if(l==r)
    {
        seg[now].ma=seg[now].mi=v;
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,now*2,v);
    update(mid+1,r,a,now*2+1,v);
    seg[now].ma=max(seg[now*2].ma,seg[now*2+1].ma);
    seg[now].mi=min(seg[now*2].mi,seg[now*2+1].mi);
}
A query(int l,int r,int a,int b,int now)
{
    A z,ll,rr;
    z.mi=1e9;
    z.ma=-1e9;
    if(l>b || r<a)
        return z;
    if(l>=a && r<=b)
    {
        return seg[now];
    }
    int mid=(l+r)>>1;
    ll=query(l,mid,a,b,now*2);
    rr=query(mid+1,r,a,b,now*2+1);
    z.mi=min(ll.mi,rr.mi);
    z.ma=max(ll.ma,rr.ma);
    return z;
}
int main()
{
    int n,k,q,a,b,x,y;
    A ans;
    scanf("%d %d",&n,&k);
    build(1,n,1);
    for(int i=1; i<=n; i++)
        arr[i]=i;
    while(k--)
    {
        scanf("%d %d %d",&q,&a,&b);
        a++,b++;
        if(q==0)
        {
            swap(arr[a],arr[b]);
            update(1,n,a,1,arr[a]);
            update(1,n,b,1,arr[b]);
        }
    if(q==1)
    {
        ans=query(1,n,a,b,1);
//            printf("%d %d\n",ans.mi,ans.ma);
        if(ans.mi==a && ans.ma==b)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    }
return 0;
}