/*
    TASK: QTREE SPOJ
    LANG: CPP
    AUTHOR: WasreK
    ALGO: HLD - Max edge cost in path
    TYPE: BATCH
    SCORE: TLE
*/
#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define LOGN 14
struct A{
    int i,v;
};
vector< A > g[N];
A vec[N];
int sz[N],p[LOGN][N],dep[N],hd[N],cha[N],pos[N],cost[N],arr[N];
int idx,now; //idx=chain idx now=position in chain(seg)
int seg[N*4],n;
char str[10];
void dfs(int u,int la){
    p[0][u]=la;
    sz[u]=1;
    dep[u]= (la!=-1) ? dep[la]+1 : 1;
    if(g[u].size()==1) return ;
    int now=(g[u][0].i==la)?1:0;
    for(int i=0; i<g[u].size(); i++){
        if(g[u][i].i==la) continue;
        dfs(g[u][i].i,u);
        sz[u]+=sz[g[u][i].i];
        if(sz[g[u][i].i] > sz[g[u][now].i]) now=i;
    }
    A a,b;
    a=g[u][0];
    b=g[u][now];
    g[u][0]=b;
    g[u][now]=a;
    return ;
}
void hld(int u,int c){
    if(!hd[idx]) hd[idx]=u; //assign head
    cha[u]=idx; //chain index
    pos[u]=++now; //position in segment (in)
    cost[now]=c; //cost
    arr[now]=u; //reverse pos[u], segment array
    if(g[u][0].i == p[0][u]) return;
    hld(g[u][0].i,g[u][0].v);
    for(int i=1;i<g[u].size();i++){
        if(g[u][i].i==p[0][u]) continue;
        idx++;
        hld(g[u][i].i,g[u][i].v);
    }
    return ;
}
void build(int l,int r,int now){
    if(l==r){
        seg[now]=cost[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    seg[now]=(seg[now*2]>seg[now*2+1]) ? seg[now*2]:seg[now*2+1];
    return ;
}
void upd(int l,int r,int now,int a,int v){
    if(l>a || r<a) return;
    if(l==r){
        seg[now]=v;
        return ;
    }
    int mid=(l+r)>>1;
    upd(l,mid,a,now*2,v);
    upd(mid+1,r,a,now*2+1,v);
    seg[now]=(seg[now*2]>seg[now*2+1]) ? seg[now*2]:seg[now*2+1];
    return ;
}
int qy(int l,int r,int a,int b,int now){
    if(b<l || a>r) return -2e9;
    if(l<=a && b<=r) return seg[now];
    int mid=(l+r)>>1;
    int ll=qy(l,mid,a,b,now*2);
    int rr=qy(mid+1,r,a,b,now*2+1);
    return (ll>rr)?ll:rr;
}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b); //a below b
    int dif=dep[a]-dep[b];
    for(int i=0;i<=LOGN;i++){
        if(dif>>i & 1) a=p[i][a];
    }
    if(a==b) return a;
    for(int i=LOGN;i>=0;i--){
        if(p[i][a]!=p[i][b]){
            a=p[i][a];
            b=p[i][b];
        }
    }
    return p[0][a];
}
int chain_que(int u,int v){
    int now=-2e9,k;
    while(1){
        if(cha[u]==cha[v]){
            k=qy(1,n,pos[v]+1,pos[u],1);
            now=(now>k)?now:k;
            return now;
        }
        //u up
        k=qy(1,n,pos[hd[cha[u]]],pos[u],1);
        now=(now>k)?now:k;
        u=p[0][hd[cha[u]]];
    }
    return now;
}
int query_ans(int a,int b){
    int lca=LCA(a,b);
    int ca=chain_que(a,lca);
    int cb=chain_que(b,lca);
    return (ca>cb)?ca:cb;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q,a,b,c;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            g[a].push_back({b,c});
            g[b].push_back({a,c});
            vec[i]={a,b};
        }
        dfs(1,-1);
        //LCA
        for(int i=1;i<=LOGN;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1][j]!=-1) p[i][j]=p[i-1][p[i-1][j]];
            }
        }
        idx=1,now=0;
        hld(1,0);
        build(1,n,1);
        while(1){
            scanf(" %s",str);
            if(str[0]=='D') break;
            scanf("%d %d",&a,&b);
            if(str[0]=='C'){
                if(p[0][vec[a].i]==vec[a].v){
                    upd(1,n,1,pos[vec[a].i],b);
                }else{
                    upd(1,n,1,pos[vec[a].v],b);
                }
            }else{
                printf("%d\n",query_ans(a,b));
            }
        }
        for(int i=1;i<=n;i++) g[i].clear(),hd[i]=0;
    }
    return 0;
}