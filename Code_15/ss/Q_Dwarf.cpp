/*
    TASK:Q_Dwarf
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int minn[800010],maxx[800010],a[200010],pos[200010];
void build(int l,int r,int now){
    if(l==r){
        minn[now]=pos[l];
        maxx[now]=pos[l];
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    minn[now]=min(minn[now*2],minn[now*2+1]);
    maxx[now]=max(maxx[now*2],maxx[now*2+1]);
}
void update(int l,int r,int now,int idx,int v){
    if(l>idx || r<idx) return ;
    if(l==r){
        minn[now] = v;
        maxx[now] = v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,now*2+1,idx,v);
    minn[now] = min(minn[now*2],minn[now*2+1]);
    maxx[now] = max(maxx[now*2],maxx[now*2+1]);
}
int query_max(int l,int r,int now ,int ll,int rr){
    if(l>rr || r<ll) return -1<<30;
    if(l>=ll && r<=rr) return maxx[now];
    int mid=(l+r)>>1;
    return max( query_max(l,mid,now*2,ll,rr) , query_max(mid+1,r,now*2+1,ll,rr) );
}
int query_min(int l,int r,int now ,int ll,int rr){
    if(l>rr || r<ll) return 1<<30;
    if(l>=ll && r<=rr) return minn[now];
    int mid=(l+r)>>1;
    return min( query_min(l,mid,now*2,ll,rr) , query_min(mid+1,r,now*2+1,ll,rr) );
}
int main(){
    int n,m,opr,r,s;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    build(1,n,1);
    while(m--){
        scanf("%d %d %d",&opr,&r,&s);
        if(opr==1){
            update(1,n,1,a[r],s);
            update(1,n,1,a[s],r);
            swap(a[r],a[s]);
        }else {
            int d = query_max(1,n,1,r,s)-query_min(1,n,1,r,s);
            if(d==s-r) printf("YES\n");
            else printf("NO\n");
        }
    }
}
