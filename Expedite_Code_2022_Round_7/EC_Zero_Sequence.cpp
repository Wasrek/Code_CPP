#include<bits/stdc++.h>
using namespace std;
#define N 200100
#define lm 200000
long long seg[N*4],lazy[4*N],a[N];
void update(int l,int r,int a,int b,int now,int v)
{
    if(lazy[now])
    {
        if(l!=r)
        {
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        seg[now]+=(r-l+1)*lazy[now];
        lazy[now]=0;
    }
    if(l>b || r<a)
        return ;
    if(l>=a && r<=b)
    {
        seg[now]+=(r-l+1)*v;
        if(l!=r)
            lazy[now*2]+=v,lazy[now*2+1]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2,v);
    update(mid+1,r,a,b,now*2+1,v);
    seg[now]=seg[now*2]+seg[now*2+1];
}
long long query(int l,int r,int a,int b,int now)
{
    if(lazy[now])
    {
        if(l!=r)
        {
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        seg[now]+=(r-l+1)*lazy[now];
        lazy[now]=0;
    }
    if(l>b || r<a) return 0;
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)>>1;
    return query(l,mid,a,b,now*2)+query(mid+1,r,a,b,now*2+1);
}
int main()
{
    int n,opr,a,b,end=1,val;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&a,&b);
            update(1,lm,1,a,1,b);
        }else if(opr==2){
            scanf("%d",&a);
            end++;
            update(1,lm,end,end,1,a);
        }else{
            val=query(1,lm,end,end,1);
            update(1,lm,end,end,1,-1*val);
            end--;
        }
        printf("%lld %d\n",query(1,lm,1,end,1),end);
    }
}
