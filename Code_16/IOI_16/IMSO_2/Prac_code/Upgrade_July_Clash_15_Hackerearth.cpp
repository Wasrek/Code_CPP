/*
    TASK:Upgrade July Clash '15
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct A{
    int v,gr,pos;
} arr[N];
struct Node{
    int prio,rev,sz,v;
    long long sum;
    struct Node *l,*r;
    Node(int idx){
        sum=v=arr[idx].v;
        rev=0;
        sz=1;
        prio=rand();
        l=r=NULL;
    }
};
struct Gr_combine{
    int cnt;
    struct Node *l=NULL,*r=NULL;
} gr[25];
typedef Node* pnode;
struct chain{
    int ma,hd;
} ch[25];
vector< int > g[N],part[4];
pnode root[25],b,c,a;
int rcnt=1,pos=0,sz[N],lvl[N],pa[N][20];
long long ans=0;
int sm(pnode t){
    return t? t->sum:0;
}
int sze(pnode t){
    return t? t->sz:0;
}
void opr(pnode t){
    if(!t) return;
    t->sum=sm(t->l)+sm(t->r)+t->v;
    t->sz=sze(t->l)+sze(t->r)+1;
}
void upd_lz(pnode t){
    if(!t || !t->rev) return;
    swap(t->l,t->r);
    if(t->l) t->l->rev^=1;
    if(t->r) t->r->rev^=1;
    t->rev=0;
}
void merge(pnode &t,pnode l,pnode r){
    if(!l && !r) return void(t=NULL);
    upd_lz(l);upd_lz(r);
    if(!l || !r) t= l? l:r;
    else if(l->prio > r->prio) t=l,merge(t->r,l->r,r);
    else t=r,merge(t->l,l,r->l);
    opr(t);
    return ;
}
void dfs(int cur,int dep){
    sz[cur]=1;
    lvl[cur]=dep;
    for(auto &x: g[cur]){
        if(sz[x]){
            swap(x,g[cur][g[cur].size()-1]);
            if(sz[x]) continue;
        }
        pa[x][0]=cur;
        dfs(x,dep+1);
        sz[cur]+=sz[x];
        if(sz[x]>sz[g[cur][0]]) swap(x,g[cur][0]);
    }
    return ;
}
void hld(int cur){
    if(!ch[rcnt].hd) ch[rcnt].hd=cur;
    arr[cur].gr=rcnt;
    arr[cur].pos=++pos;
    merge(root[rcnt],root[rcnt],new Node(cur));
    ch[rcnt].ma=pos;
    if(!g[cur].size() || arr[g[cur][0]].gr) return ;
    hld(g[cur][0]);

    for(int i=1;i<g[cur].size();i++){
        if(arr[g[cur][i]].gr) continue;
        ch[rcnt].ma=pos;
        ++rcnt;
        hld(g[cur][i]);
    }

    return ;
}
int lca(int u,int v){
    if(lvl[u]<lvl[v]) swap(u,v);
    int dif=lvl[u]-lvl[v];
    for(int i=0;i<19;i++) if(dif<<i & 1) u=pa[u][i];
    if(u==v) return u;
    for(int i=18;i>=0;i--){
        if(pa[u][i]!=pa[v][i]) u=pa[u][i],v=pa[v][i];
    }
    return pa[u][0];
}
void split(pnode t,pnode &l,pnode &r,int k){
    if(!t) return void(l=r=NULL);
    upd_lz(t);
    int cur_pos=1+sze(t->l);
    if(cur_pos<=k) l=t,split(t->r,l->r,r,k-cur_pos);
    else r=t,split(t->l,l,r->l,k);
    opr(t);
    return ;
}
void rev_tree(int u,int v,pnode &t){
    int anc=lca(u,v);
    t=b=c=NULL;
    if(arr[u].pos>arr[v].pos) swap(u,v);
    while(arr[u].gr!=arr[anc].gr){
        // head->pa(now u) + head->u
        part[0].push_back(arr[u].gr);
        gr[arr[u].gr].cnt=arr[u].pos-arr[ch[arr[u].gr].hd].pos+1;
        split(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r,gr[arr[u].gr].cnt);
        merge(t,root[arr[u].gr],t);
        u=pa[ch[arr[u].gr].hd][0];
    }
    // we want path oriu-> head + tail->head + tail->head
    if(t)t->rev=1;//flip
    // path head->v + head-v + head-> oriv
    while(arr[v].gr!=arr[anc].gr){
        // head->pa(now u) + head->u
        part[2].push_back(arr[v].gr);
        gr[arr[v].gr].cnt=arr[v].pos-arr[ch[arr[v].gr].hd].pos+1;
        split(root[arr[v].gr],root[arr[v].gr],gr[arr[v].gr].r,gr[arr[v].gr].cnt);
        merge(c,root[arr[v].gr],c);
        v=pa[ch[arr[v].gr].hd][0];
    }
    if(arr[u].pos>arr[v].pos) swap(u,v);
    part[1].push_back(arr[u].gr);
    split(root[arr[u].gr],gr[arr[u].gr].l,root[arr[u].gr],arr[u].pos-arr[ch[arr[u].gr].hd].pos);
    gr[arr[u].gr].cnt=arr[v].pos-arr[u].pos+1;
    split(root[arr[u].gr],b,gr[arr[u].gr].r,gr[arr[u].gr].cnt);
    merge(t,t,b);
    merge(t,t,c);

    if(t) t->rev^=1;
    c=NULL;
    for(int i=0;i<3;i++)
    for(auto x: part[i]){
        split(t,c,t,gr[x].cnt);
        merge(root[x],gr[x].l,c);
        merge(root[x],root[x],gr[x].r);
    }
    part[0].clear();
    part[1].clear();
    part[2].clear();
}
void getsum(int u,int v){
    ans=0;
    int anc=lca(u,v);
    while(arr[u].gr!=arr[anc].gr){
        gr[arr[u].gr].cnt=arr[u].pos-arr[ch[arr[u].gr].hd].pos+1;
        split(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r,gr[arr[u].gr].cnt);
        if(root[arr[u].gr]) ans+=root[arr[u].gr]->sum;
        merge(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r);
        u=pa[ch[arr[u].gr].hd][0];
    }
    while(arr[v].gr!=arr[anc].gr){
        gr[arr[v].gr].cnt=arr[v].pos-arr[ch[arr[v].gr].hd].pos+1;
        split(root[arr[v].gr],root[arr[v].gr],gr[arr[v].gr].r,gr[arr[v].gr].cnt);
        if(root[arr[v].gr]) ans+=root[arr[v].gr]->sum;
        merge(root[arr[v].gr],root[arr[v].gr],gr[arr[v].gr].r);
        v=pa[ch[arr[v].gr].hd][0];
    }
    a=NULL;
    if(arr[u].pos>arr[v].pos) swap(u,v);
    split(root[arr[u].gr],gr[arr[u].gr].l,root[arr[u].gr],arr[u].pos-arr[ch[arr[u].gr].hd].pos);
    gr[arr[u].gr].cnt=arr[v].pos-arr[u].pos+1;
    split(root[arr[u].gr],a,gr[arr[u].gr].r,gr[arr[u].gr].cnt);
    if(a) ans+=a->sum;
    merge(root[arr[u].gr],gr[arr[u].gr].l,a);
    merge(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r);
    return ;
}
int main()
{
    srand(time(NULL));
    int n,q,u,v;
    char c;
    pnode uv;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i].v);
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    hld(1);
    for(int i=1;i<=18;i++){
        for(int j=1;j<=n;j++){
            if(pa[j][i]) pa[j][i]=pa[pa[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=q;i++){
        scanf(" %c %d %d",&c,&u,&v);
        if(c=='R'){
            rev_tree(u,v,a);
        }else{
            getsum(u,v);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
5 3
1 2 4 8 16
1 2
1 3
2 4
2 5
S 4 3
R 5 1
S 3 4
*/