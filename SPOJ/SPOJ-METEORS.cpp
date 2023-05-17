/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: Wrong answer at case 27 - SPOJ
*/
#include<bits/stdc++.h>
using namespace std;
#define N 300010
int w[N],a[N],idx=0,root[N];
struct A{
    long long v;
    int l,r;
    long long lz;
};
A seg[48*N];
void update(int l,int r,int &now,int last,int ul,int ur,long long v,bool ch){
    if(last!=-1){
        if(seg[last].lz){
            if(l!=r){
                if(seg[last].l==-1) seg[last].l=++idx,seg[idx]={0,-1,-1,0};
                else seg[++idx]=seg[seg[last].l],seg[last].l=idx;
                if(seg[last].r==-1) seg[last].r=++idx,seg[idx]={0,-1,-1,0};
                else seg[++idx]=seg[seg[last].r],seg[last].r=idx;
                seg[seg[last].l].lz+=seg[last].lz;  
                seg[seg[last].r].lz+=seg[last].lz;
            }else seg[last].v+=seg[last].lz;
            seg[last].lz=0;
        }
        now=last;
        if(ch && (ur<l || ul>r)) return ;
        if(!ch && (l>ul && r<ur)) return ;
        now=++idx;
        seg[now]=seg[last];
    }else{
        now=-1;
        if(ch && (ur<l || ul>r)) return ;
        if(!ch && (l>ul && r<ur)) return ;
        now=++idx,seg[now]={0,-1,-1,0};
        // printf("%d %d %d %d %d %d %d\n",l,r,now,last,ul,ur,v);
    }
    if(ch && (l>=ul && r<=ur)){
        if(l!=r)seg[now].lz+=v;
        else seg[now].v+=v;
        return ;
    }
    // printf("%d %d %d %d %d %d %d\n",l,r,now,last,ul,ur,v);
    if(!ch && (r<=ul || l>=ur)){
        if(l!=r)seg[now].lz+=v;
        else seg[now].v+=v;
        return ;
    }
    int mid=(l+r)>>1,L,R;
    update(l,mid,L,seg[now].l,ul,ur,v,ch);
    update(mid+1,r,R,seg[now].r,ul,ur,v,ch);
    seg[now]={seg[now].v,L,R,seg[now].lz};
    return ;
}
long long qy(int l,int r,int a,int now){
    if(seg[now].lz){
        if(l!=r){
            if(seg[now].l==-1) seg[now].l=++idx,seg[idx]={0,-1,-1,0};
            else seg[++idx]=seg[seg[now].l],seg[now].l=idx;
            if(seg[now].r==-1) seg[now].r=++idx,seg[idx]={0,-1,-1,0};
            else seg[++idx]=seg[seg[now].r],seg[now].r=idx;
            seg[seg[now].l].lz+=seg[now].lz;  
            seg[seg[now].r].lz+=seg[now].lz;
        }else seg[now].v+=seg[now].lz;
        seg[now].lz=0;
    }
    if(l==r) return seg[now].v;
    int mid=(l+r)>>1;
    if(a<=mid){
        return qy(l,mid,a,seg[now].l);
    }else{
        return qy(mid+1,r,a,seg[now].r);
    }
}
vector< int > g[N];
int main()
{
    int n,m,k,l,r,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        g[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    root[0]=0;
    seg[0]={0,-1,-1,0};
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&l,&r,&v);
        if(l<r) update(1,m,root[i],root[i-1],l,r,v,1);
        else {
            update(1,m,root[i],root[i-1],r,l,v,0);
        }
    }
    int mid,now;
    for(int i=1;i<=n;i++){
        l=1; r=k+1;
        while(l<r){
            mid=(l+r)>>1;
            now=0;
            for(auto x: g[i]){
                now+=qy(1,m,x,root[mid]);
            }
            // printf("%d %d %d %d %d %d\n",i,l,r,mid,now,w[i]);
            if(now>=w[i]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(l>k) printf("NIE\n");
        else printf("%d\n",l);
    }
    // for(int i=1;i<=k;i++) printf("%d ",root[i]);
    // printf("\n");
    // for(int i=0;i<=idx;i++){
    //     printf("%d %d %d %d %d\n",i,seg[i].v,seg[i].l,seg[i].r,seg[i].lz);
    // }
    // for(int i=1;i<=k;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%lld ",qy(1,m,j,root[i]));
    //     }
    //     printf("\n");
    // }

    return 0;
}