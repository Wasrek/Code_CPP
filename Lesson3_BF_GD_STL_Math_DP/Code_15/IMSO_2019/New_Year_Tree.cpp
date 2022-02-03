/*
    TASK:New_Year_Tree
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 400010
int cnt=0,s[N],c[N],n;
struct A {
    int ha,ma[61],c;
};
struct B{
    int s,e;
};
B wh[N*2];
A seg[N*4];
int lazy[4*N];
vector< int > g[N*4];
void dfs(int i){
    s[++cnt]=i;
    for(auto x: g[i]){
        dfs(x);
        s[++cnt]=x;
    }
    return ;
}
void build(int l,int r,int now){
    if(l==r){
        seg[now].ma[c[s[l]]]=1;
        seg[now].ha=1;
        seg[now].c=c[s[l]];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now].ha=0;
    for(int i=1;i<=60;i++){
        if(seg[now*2].ma[i] || seg[now*2+1].ma[i])seg[now].ha++,seg[now].ma[i]=1;
    }
    return ;
}
void update(int l,int r,int a,int b,int now,int c){
    if(lazy[now]){
        memset(seg[now].ma,0,sizeof seg[now].ma);
        seg[now].ma[lazy[now]]=1;
        seg[now].ha=1;
        seg[now].c=lazy[now];
        if(l!=r){
            lazy[now*2]=lazy[now];
            lazy[now*2+1]=lazy[now];
        }
        lazy[now]=0;
    }
    if(l> b || r<a) return ;
    if(l>=a && r<=b){
        memset(seg[now].ma,0,sizeof seg[now].ma);
        seg[now].ma[c]=1;
        seg[now].ha=1;
        seg[now].c=c;
        if(l!=r){
            lazy[now*2]=c;
            lazy[now*2+1]=c;
        }
        return ;
    }
    int mid=(l+r)>>1;
    update(l,mid,a,b,now*2,c);
    update(mid+1,r,a,b,now*2+1,c);
    seg[now].ha=0;
    for(int i=1;i<=60;i++){
        if(seg[now*2].ma[i] || seg[now*2+1].ma[i])seg[now].ha++,seg[now].ma[i]=1;    
    }
}
A query(int l,int r,int a,int b,int now){
    A z;
    z.ha=0;
    z.c=0;
    memset(z.ma,0,sizeof z.ma);
    if(l>b || r<a) return z;
    if(lazy[now]){
        memset(seg[now].ma,0,sizeof seg[now].ma);
        seg[now].ma[lazy[now]]=1;
        seg[now].ha=1;
        seg[now].c=lazy[now];
        if(l!=r){
            lazy[now*2]=lazy[now];
            lazy[now*2+1]=lazy[now];
        }
        lazy[now]=0;
    }
    if(l>=a && b>=r)return seg[now];
    int mid=(l+r)>>1;
    A ll=query(l,mid,a,b,now*2);
    A rr= query(mid+1,r,a,b,now*2+1);
    z.ha=0;
    for(int i=1;i<=60;i++){
        z.ma[i]=max(ll.ma[i],rr.ma[i]);
        if(ll.ma[i] || rr.ma[i])z.ha++;
    }
    return z;
}
A ans;
int main()
{
    int m,p,a,b,opr;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }
    dfs(1);
    s[++cnt]=1;
    for(int i=1;i<=cnt;i++){
        if(wh[s[i]].s==0){
            wh[s[i]].s=i;
        }else wh[s[i]].e=i;
        printf("%d ",s[i]);
    }
    printf("\n");
     build(1,cnt,1);
    // for(int i=1;i<=cnt*4;i++){
    //             printf("%d ",seg[i].ha);
    //         }
    printf("\n");
    for(int i=1;i<=m;i++){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&a,&b);
            update(1,cnt,wh[a].s,wh[a].e,1,b);
            // printf("%d\n",seg[1].ha);
            // for(int i=1;i<=cnt*4;i++){
            //     printf("%d ",seg[i].ha);
            // }
            // printf("\n");
        }
        else{
            scanf("%d",&a);
            ans=query(1,cnt,wh[a].s,wh[a].e,1);
            printf("%d\n",ans.ha);
        }
    }
    return 0;
}