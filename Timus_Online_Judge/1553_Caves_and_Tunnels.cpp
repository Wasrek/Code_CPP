/*
    TASK: 1553 Cavess and Tunnels acm Timus
    LANG: CPP
    AUTHOR: WasreK
    ALGO: HLD
    TYPE: BATCH
    SCORE: 100 
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
#define LOGN 17
struct A{
    int i,v;
};
vector<int> g[N];
int sz[N],p[LOGN+10][N],dep[N],hd[N],cha[N],pos[N],arr[N];
int idx,now; //idx=chain idx now=position in chain(seg)
int seg[N*4],n;
void dfs(int u,int la){
    p[0][u]=la;
    sz[u]=1;
    dep[u]= (la!=-1) ? dep[la]+1 : 1;
    if((g[u].size()<=1 && g[u][0]==la) || !g[u].size()) return ;
    int k=(g[u][0]==la)?1:0;
    for(int i=0; i<g[u].size(); i++){
        if(g[u][i]==la) continue;
        dfs(g[u][i],u);
        sz[u]+=sz[g[u][i]];
        if(sz[g[u][i]] > sz[g[u][k]]) k=i;
    }
    swap(g[u][0],g[u][k]);
    return ;
}
void hld(int u){
    if(!hd[idx]) hd[idx]=u; //assign head
    cha[u]=idx; //chain index
    pos[u]=++now; //position in segment (in)
    arr[now]=u; //reverse pos[u], segment array
    if(!g[u].size() || g[u][0] == p[0][u]) return;
    hld(g[u][0]);
    for(int i=1;i<g[u].size();i++){
        if(g[u][i]==p[0][u]) continue;
        idx++;
        hld(g[u][i]);
    }
    return ;
}
void upd(int l,int r,int now,int a,int v){
    if(l>a || r<a) return;
    if(l==r){
        seg[now]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    upd(l,mid,now*2,a,v);
    upd(mid+1,r,now*2+1,a,v);
    seg[now]=(seg[now*2]>seg[now*2+1]) ? seg[now*2]:seg[now*2+1];
    return ;
}
int qy(int l,int r,int a,int b,int now){
    if(b<l || a>r) return -2e9;
    if(a<=l && r<=b) return seg[now];
    int mid=(l+r)>>1;
    int ll=qy(l,mid,a,b,now*2);
    int rr=qy(mid+1,r,a,b,now*2+1);
    return (ll>rr)?ll:rr;
}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b); //so that a below b
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
    int now=-2e9;
    while(1){
        if(cha[u]==cha[v]){
            now=max(now,qy(1,n,pos[v],pos[u],1));
            return now;
        }
        //u up
        now=max(now,qy(1,n,pos[hd[cha[u]]],pos[u],1));
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
    int q,a,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    //LCA
    for(int i=1;i<=LOGN;i++){
        for(int j=1;j<=n;j++){
            if(p[i-1][j]!=-1) p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    idx=1,now=0;
    hld(1);
    scanf("%d",&q);
    char ch;
    while(q--){
        scanf(" %c %d %d",&ch,&a,&b);
        if(ch=='I'){
            upd(1,n,1,pos[a],b);
        }else{
            printf("%d\n",query_ans(a,b));
        }
    }
    return 0;
}