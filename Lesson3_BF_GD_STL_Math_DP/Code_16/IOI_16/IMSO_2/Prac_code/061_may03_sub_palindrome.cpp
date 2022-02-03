/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100010
#define iden 311
#define MOD 10000019
struct A{
    long long sum,cnt,l,r;
} seg[5][SIZE*30];
char str[SIZE];
long long pre[SIZE],pos[SIZE],power[SIZE],pld[5][SIZE];
vector<long long> p[5];
int n,root[5][SIZE],newid=0;
void upd(int ver,int l,int r,int &a,int b,int v,int idx){
    a=b;
    if(l>idx || r<idx) return;
    a=++newid;
    // printf("seg %d %d %d %d\n",ver,l,r,idx);
    seg[ver][a]=seg[ver][b];
    if(l==r){
        seg[ver][a].sum+=v;
        seg[ver][a].cnt++;
        return ;
    }
    int mid=(l+r)>>1,L,R;
    upd(ver,l,mid,L,seg[ver][a].l,v,idx);
    upd(ver,mid+1,r,R,seg[ver][a].r,v,idx);
    seg[ver][a]={seg[ver][L].sum+seg[ver][R].sum,seg[ver][L].cnt+seg[ver][R].cnt,L,R};
    return ;
}
void solve_dp(){
    power[0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=(((pre[i-1]*iden)%MOD)+str[i])%MOD;
        power[i]=(power[i-1]*iden)%MOD;
    }
    for(int i=n;i>0;i--){
        pos[i]=(((pos[i+1]*iden)%MOD)+str[i])%MOD;
    }
    int l,r,mid,pl,pr;
    for(int i=1;i<=n;i++){
        l=0,r=min(i,n-i+1);
        while(l<r){
            mid=(l+r+1)>>1;
            pl=((pre[i]-((pre[i-mid]*power[mid])%MOD)+MOD)%MOD);
            pr=((pos[i]-((pos[i+mid]*power[mid])%MOD)+MOD)%MOD);
            if(pl==pr) l=mid;
            else r=mid-1;
        }
        pld[0][i]=l-i; pld[1][i]=i+l;
        p[0].push_back(l-i); p[1].push_back(i+l);
        l=0,r=min(i,n-i);
        while(l<r){
            mid=(l+r+1)>>1;
            pl=((pre[i]-((pre[i-mid]*power[mid])%MOD)+MOD)%MOD);
            pr=((pos[i+1]-((pos[i+1+mid]*power[mid])%MOD)+MOD)%MOD);
            if(pl==pr) l=mid;
            else r=mid-1;
        }
        pld[2][i]=l-i; pld[3][i]=i+l;
        p[2].push_back(l-i); p[3].push_back(i+l);
    }
    for(int i=0;i<=3;i++){
        p[i].push_back(-1e18);
        sort(p[i].begin(),p[i].end());
        p[i].resize(unique(p[i].begin(),p[i].end())-p[i].begin());
    }
}
void persistent(){
    int lb;
    for(int i=0;i<=3;i++){
        seg[i][0]={0,0,0,0};
        root[i][0]=0;
        for(int j=1;j<=n;j++){
            lb=lower_bound(p[i].begin(),p[i].end(),pld[i][j])-p[i].begin();
            // printf("upd %d %d %d %d\n",i,j,pld[i][j],lb);
            upd(i,1,p[i].size(),root[i][j],root[i][j-1],pld[i][j],lb);
        }
    }
}
A que(int ver,int l,int r,int a,int b,int idx){
    if(idx<l) return {0,0,0,0}; 
    if(r<=idx) return {seg[ver][b].sum-seg[ver][a].sum,seg[ver][b].cnt-seg[ver][a].cnt};
    int mid=(l+r)>>1;
    A L,R;
    L=que(ver,l,mid,seg[ver][a].l,seg[ver][b].l,idx);
    R=que(ver,mid+1,r,seg[ver][a].r,seg[ver][b].r,idx);
    return {L.sum+R.sum,L.cnt+R.cnt};
}
long long find(int ver,int l,int r,int u,int idx){
    int lb=upper_bound(p[ver].begin(),p[ver].end(),idx)-p[ver].begin();
    lb--;
    A qy=que(ver,1,p[ver].size(),root[ver][l-1],root[ver][r],lb);
    long long cnt=seg[ver][root[ver][r]].cnt-seg[ver][root[ver][l-1]].cnt;
    cnt-=qy.cnt;
    return cnt*idx+qy.sum+(u*(r-l+1)*(l+r)/2);
}
long long solve(int l,int r){
    long long odl,odr,evl,evr;
    int m1=(l+r)>>1;
    int m2=(l+r-1)>>1;
    odl=find(0,l,m1,1,1-l);
    odr=find(1,m1+1,r,-1,r+1);
    evl=find(2,l,m2,1,1-l);
    evr=find(3,m2+1,r,-1,r);
    return odl+odr+evl+evr;
}
int main()
{
    scanf("%d",&n);
    scanf(" %s",str+1);
    solve_dp();
    persistent();
    // for(int i=0;i<=3;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%d %d %d %d\n",i,j,seg[i][root[i][j]].sum,seg[i][root[i][j]].cnt);
    //     }
    // }
    int q,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&l,&r);
        printf("%lld\n",solve(l,r));
    }
    return 0;
}