/*
    TASK:o59_mar_c1_atleast
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct A{
    long long sum,cnt;
    int l,r;
} seg[24*N];
int mp[N],root[N],idx=0;
pair<int,int> sot[N];
long long all;
void build(int l,int r,int &now){
    now=++idx;
    if(l==r){
        seg[now]={0,0,-1,-1};
        return ;
    }
    int L,R,mid=(l+r)>>1;
    build(l,mid,L);
    build(mid+1,r,R);
    seg[now]={0,0,L,R};
    return ;
}
void upd(int l,int r,int &now,int last,int tg){
    now=last;
    if(l>tg || tg>r) return ;
    now=++idx;
    seg[now]=seg[last];
    if(l==r){
        seg[now]={sot[tg].first,1,-1,-1};
        return ;
    }
    int L,R,mid=(l+r)>>1;
    upd(l,mid,L,seg[now].l,tg);
    upd(mid+1,r,R,seg[now].r,tg);
    seg[now]={seg[L].sum+seg[R].sum,seg[L].cnt+seg[R].cnt,L,R};
    return ;
}
int que(int l,int r,int a ,int b,long long sum,double k,int cou){
    if(l==r){
        if((double)(all-sum)/cou >= k){
            return cou;
        }else{
            return cou-(seg[b].cnt-seg[a].cnt);
        }
    }
    int mid=(l+r)>>1;
    long long lef=seg[seg[b].l].sum-seg[seg[a].l].sum;
    int cnt=seg[seg[b].l].cnt-seg[seg[a].l].cnt;
    if((double)(all-lef-sum)/(cou-cnt) >= k || lef==all){
        return que(l,mid,seg[a].l,seg[b].l,sum,k,cou);
    }else{
        return que(mid+1,r,seg[a].r,seg[b].r,sum+lef,k,cou-cnt);
    }
}
int main()
{
    int n,m,qy,a,b;
    double k;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&sot[i].first);
        sot[i].second=i;
    }
    sort(sot+1,sot+1+n);
    for(int i=1;i<=n;i++){
        mp[sot[i].second]=i;
    }
    build(1,n,root[0]);
    for(int i=1;i<=n;i++){
        upd(1,n,root[i],root[i-1],mp[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %lf",&a,&b,&k);
        all=seg[root[b]].sum-seg[root[a-1]].sum;
        qy=que(1,n,root[a-1],root[b],0,k,b-a+1);
        printf("%d\n",qy<=0 ? -1:(b-a+1)-qy);
    }
    return 0;
}
/*
11 4
6 5 4 3 2 1 2 3 4 5 6
1 11 3
2 10 3.55
5 8 3.5
1 11 7
*/