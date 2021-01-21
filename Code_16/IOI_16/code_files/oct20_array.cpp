/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 1 << 18
struct A{
    int opr,a,b,v;
};
long long seg[N << 1],lz[N << 1];
queue< A > q;
set< int > g;
vector<int> gg;
//map<int,int> mp,re;
int re[N << 1];
void lzpush(int l,int r,int now){
    if(lz[now]==1ll<<30) return ;
    if(l!=r){
        lz[now*2ll]=lz[now*2ll+1ll]=lz[now];
    }
    seg[now]=(long long)(re[r+1]-re[l])*lz[now];
    // printf("%d %d %d %d %d\n",l,r,re[l],re[r],seg[now]);
    lz[now]=1ll<<30;
    return ;
}
void update(int l,int r,int a,int b,long long v,int now){
    lzpush(l,r,now);
    if(l>b || r<a) return ;
    if(l>=a && r<=b){
        lz[now]=v;
        lzpush(l,r,now);
        return ;
    }
    int mid=(l+r)>>1ll;
    update(l,mid,a,b,v,now*2ll);
    update(mid+1ll,r,a,b,v,now*2ll+1ll);
    seg[now]=seg[now*2ll]+seg[now*2ll+1ll];
    return ;
}
long long query(int l,int r,int a,int b,int now){
    lzpush(l,r,now);
    if(l>b || r<a) return 0ll;
    if(l>=a && r<=b){
        return seg[now];
    }
    int mid=(l+r)>>1ll;
    return query(l,mid,a,b,now*2ll)+query(mid+1,r,a,b,now*2ll+1ll);
}
int main()
{
    int n,k,opr,a,b,v;
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&opr);
        if(!opr){
            scanf("%d %d %d",&a,&b,&v);
//            b--;
            q.push({opr,a,b,v});
        }else{
            scanf("%d %d",&a,&b);
//            b--;
            q.push({opr,a,b,0});
        }
        g.insert(a),g.insert(b);
        //if(!mp[a])g.push_back(a),mp[a]=1;
        //if(!mp[b])g.push_back(b),mp[b]=1;
    }
    //if(!mp[0]) g.push_back(0);
    //if(!mp[n]) g.push_back(n);
    g.insert(0),g.insert(n);
    //sort(g.begin(),g.end());
    int cou=0;
    for(auto x: g){
      //  mp[x]=++cou;
      gg.push_back(x);
        re[++cou]=x;
     //    printf("%d %d\n",x,cou);
    }
    for(int i=1;i< N << 1;i++) lz[i]=1<<30;
    while(!q.empty()){
        int itl = lower_bound(gg.begin(),gg.end(),q.front().a)-gg.begin();
        int itr = lower_bound(gg.begin(),gg.end(),q.front().b)-gg.begin();
        itl++;
        if(!q.front().opr){
            //cout << mp[q.front().a] << ' ' << mp[q.front().b]-1 << endl;

            update(1,cou,itl,itr,q.front().v,1);
            // printf("upd %d %d %d\n",mp[q.front().a],mp[q.front().b],q.front().v);
            // printf("%lld\n",seg[1]);
        }else{
            printf("%lld\n",query(1,cou,itl,itr,1));
        }
        q.pop();
    }
    return 0;
}