/*
    TASK: Sign on Fence 484E
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct A{
    int ma,pre,suf,l,r;
} seg[24*N];
pair<int,int> a[N];
map<int,int> mp,rm;
vector< int > g[N];
int idx=0,root[N],h=0,n;
A qy;
void ud_s(A &a,A l,A r,int szl,int szr){
    int ma=max(l.ma,max(r.ma,l.suf+r.pre));
    int pre=(l.ma==szl) ? l.ma+r.pre:l.pre;
    int suf=(r.ma==szr) ? r.ma+l.suf:r.suf;
    a={ma,pre,suf};
    return ;
}
void build(int l,int r,int &a,int b,int id){
    a=b;
    if(id<l || id>r) return ;
    a=++idx;
    seg[a]=seg[b];
    if(l==r){
        seg[a]={1,1,1,0,0};
        return ;
    }
    int L,R,mid=(l+r)>>1;
    build(l,mid,L,seg[a].l,id);
    build(mid+1,r,R,seg[a].r,id);
    ud_s(seg[a],seg[L],seg[R],(mid-l+1),(r-mid));
    seg[a].l=L;seg[a].r=R;
    return ;
}
A que(int l,int r,int a,int b,int now){
    if(r<a || l>b) return {0,0,0,0,0};
    if(l>=a && r<=b) return seg[now];
    int mid=(l+r)>>1;
    ud_s(qy,que(l,mid,a,b,seg[now].l),que(mid+1,r,a,b,seg[now].r),mid-l+1,r-mid);
    return qy;
}
void bs(int L,int R,int w){
    int l=1,r=h;
    while(l<r){
        int mid=(l+r+1)>>1;
        qy=que(1,n,L,R,root[mid]);
        if(qy.ma<w) r=mid-1;
        else l=mid;
    }
    printf("%d\n",rm[l]);
}
int main()
{
    int m,l,r,w;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(!mp[a[i].first]) mp[a[i].first]=++h;
        rm[mp[a[i].first]]=a[i].first;
        g[mp[a[i].first]].push_back(a[i].second);
    }
    seg[0]={0,0,0,0,0};
    for(int i=h;i>0;i--){
        build(1,n,root[i],root[i+1],g[i][0]);
        for(int j=1;j<g[i].size();j++){
            build(1,n,root[i],root[i],g[i][j]);
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&l,&r,&w);
        bs(l,r,w);
    }
    return 0;
}