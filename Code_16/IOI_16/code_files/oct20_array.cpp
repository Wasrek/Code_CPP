/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200100
struct A{
    long long opr,a,b,v;
};
long long seg[N*4],lz[N*4];
queue< A > q;
vector< long long > g;
map<long long,long long> mp,re;
void lzpush(long long l,long long r,long long now){
    if(lz[now]==1ll<<30) return ;
    if(l!=r){
        lz[now*2ll]=lz[now*2ll+1ll]=lz[now];
    }
    seg[now]=(re[r]-re[l]+1ll)*lz[now];
    // printf("%d %d %d %d %d\n",l,r,re[l],re[r],seg[now]);
    lz[now]=1ll<<30;
    return ;
}
void update(long long l,long long r,long long a,long long b,long long v,long long now){
    lzpush(l,r,now);
    if(l>b || r<a) return ;
    if(l>=a && r<=b){
        lz[now]=v;
        lzpush(l,r,now);
        return ;
    }
    long long mid=(l+r)>>1ll;
    update(l,mid,a,b,v,now*2ll);
    update(mid+1ll,r,a,b,v,now*2ll+1ll);
    seg[now]=seg[now*2ll]+seg[now*2ll+1ll];
    return ;
}
long long query(long long l,long long r,long long a,long long b,long long now){
    lzpush(l,r,now);
    if(l>b || r<a) return 0ll;
    if(l>=a && r<=b){
        return seg[now];
    }
    long long mid=(l+r)>>1ll;
    return query(l,mid,a,b,now*2ll)+query(mid+1,r,a,b,now*2ll+1ll);
}
int main()
{
    long long n,k,opr,a,b,v;
    scanf("%lld %lld",&n,&k);
    while(k--){
        scanf("%lld",&opr);
        if(!opr){
            scanf("%lld %lld %lld",&a,&b,&v);
            b--;
            q.push({opr,a,b,v});
        }else{
            scanf("%lld %lld",&a,&b);
            b--;
            q.push({opr,a,b,0});
        }
        if(!mp[a])g.push_back(a),mp[a]=1;
        if(!mp[b])g.push_back(b),mp[b]=1;
    }
    sort(g.begin(),g.end());
    int cou=0;
    for(auto x: g){
        mp[x]=++cou;
        re[cou]=x;
        // printf("%d %d\n",x,cou);
    }
    for(int i=1;i<=cou*4;i++) lz[i]=1<<30;
    while(!q.empty()){
        if(!q.front().opr){
            update(1,cou,mp[q.front().a],mp[q.front().b],q.front().v,1);
            // printf("upd %d %d %d\n",mp[q.front().a],mp[q.front().b],q.front().v);
            // printf("%lld\n",seg[1]);
        }else{
            printf("%lld\n",query(1,cou,mp[q.front().a],mp[q.front().b],1));
        }
        q.pop();
    }
    return 0;
}