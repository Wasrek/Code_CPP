/*
    TASK:Q_Dwarf
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200100
int maxx[4*N],minn[4*N],po[N],g[N];
void build(int l,int r,int now){
    if(l==r){
        maxx[now]=po[l];
        minn[now]=po[l];
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    minn[now]=min(minn[now*2],minn[now*2+1]);
    maxx[now]=max(maxx[now*2],maxx[now*2+1]);
}
void update(int l,int r,int now,int a,int v){
    if(r<a || l>a) return ;
    if(l==r){
        minn[now]=v;
        maxx[now]=v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,a,v);
    update(mid+1,r,now*2+1,a,v);
    minn[now]=min(minn[now*2],minn[now*2+1]);
    maxx[now]=max(maxx[now*2],maxx[now*2+1]);
}
int query_mi(int l,int r,int now,int a,int b){
    if(r<a || l>b) return 1e9;
    if(l>=a && r<=b) return minn[now];
    int mid = (l+r)/2;
    return min(query_mi(l,mid,now*2,a,b),query_mi(mid+1,r,now*2+1,a,b));
}
int query_ma(int l,int r,int now,int a,int b){
    if(r<a || l>b) return -1e9;
    if(l>=a && r<=b) return maxx[now];
    int mid = (l+r)/2;
    return max(query_ma(l,mid,now*2,a,b),query_ma(mid+1,r,now*2+1,a,b));
}
int main()
{
    int n,m,opr,a,b,qq;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&g[i]);
        po[g[i]]=i;
    }
    build(1,n,1);
    while(m--){
        scanf(" %d %d %d",&opr,&a,&b);
        if(opr==1){
            update(1,n,1,g[a],b);
            update(1,n,1,g[b],a);
            swap(g[a],g[b]);
        }else{
            qq=query_ma(1,n,1,a,b)-query_mi(1,n,1,a,b);
            if(qq==b-a)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
