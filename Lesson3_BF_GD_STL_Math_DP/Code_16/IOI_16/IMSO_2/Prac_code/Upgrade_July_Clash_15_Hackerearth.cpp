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
    long long prio,rev,sz,v,sum;
    struct Node *l,*r;
    Node(int idx){
        sum=v=arr[idx].v;
        rev=0;
        sz=1;
        prio=rand()*rand();
        l=r=NULL;
    }
};
struct Gr_combine{
    int cnt;
    struct Node *l=NULL,*r=NULL;
} gr[N];
typedef Node* pnode;
struct chain{
    int ma,hd;
} ch[N];
vector< int > g[N],part[3];
pnode root[N],b,c,a;
int rcnt=1,pos=0,sz[N],lvl[N],pa[20][N];
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
void dfs(int cur,int la){
    sz[cur]=1;
    lvl[cur]=lvl[la]+1;
    pa[0][cur]=la;
    for(int i=1;i<=19;i++){
        pa[i][cur]=pa[i-1][pa[i-1][cur]];
    }
    for(auto &x: g[cur]){
        if(x==la) continue;
        dfs(x,cur);
        sz[cur]+=sz[x];
        if((x!=la && sz[x]>sz[g[cur][0]]) || g[cur][0]==la) swap(x,g[cur][0]);
    }
    return ;
}
void hld(int cur){
    if(!ch[rcnt].hd) ch[rcnt].hd=cur;
    arr[cur].gr=rcnt;
    arr[cur].pos=++pos;
    ch[rcnt].ma=pos;
    merge(root[rcnt],root[rcnt],new Node(cur));
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
    for(int i=0;i<=19;i++){
        if(dif>>i & 1) u=pa[i][u];
    }
    if(u==v) return u;
    for(int i=18;i>=0;i--){
        if(pa[i][u]!=pa[i][v]) u=pa[i][u],v=pa[i][v];
    }
    return pa[0][u];
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
    if(u==v) return ;
    if(arr[u].pos>arr[v].pos) swap(u,v);
    // printf("%d %d %d\n",u,v,anc);
    while(arr[u].gr!=arr[anc].gr){
        // head->pa(now u) + head->u
        part[0].push_back(arr[u].gr);
        gr[arr[u].gr].cnt=arr[u].pos-arr[ch[arr[u].gr].hd].pos+1;
        split(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r,gr[arr[u].gr].cnt);
        //head-> u -> tail
        //t = head-> u ->t
        //gr[arr[u].gr].r = u->tail
        merge(t,root[arr[u].gr],t);
        u=pa[0][ch[arr[u].gr].hd];
    }
    // u-> head-> u-> head
    // cout<< "first: "<<'\n';
    // printtree(t);
    // cout<<'\n';
    if(t)t->rev^=1;//flip
    // cout<< "first flip: "<<'\n';
    // printtree(t);
    // cout<<'\n';
    // path head->v + head-v + head-> oriv
    while(arr[v].gr!=arr[anc].gr){
        // head->pa(now u) + head->u
        part[2].push_back(arr[v].gr);
        gr[arr[v].gr].cnt=arr[v].pos-arr[ch[arr[v].gr].hd].pos+1;
        split(root[arr[v].gr],root[arr[v].gr],gr[arr[v].gr].r,gr[arr[v].gr].cnt);
        merge(c,root[arr[v].gr],c);
        v=pa[0][ch[arr[v].gr].hd];
    }
    //c = head->v + head->v
    // cout<< "last: "<<'\n';
    // printtree(c);
    // cout<<'\n';

    bool swp=0;
    if(arr[u].pos>arr[v].pos) swap(u,v),swp=1;
    part[1].push_back(arr[u].gr);
    split(root[arr[u].gr],gr[arr[u].gr].l,root[arr[u].gr],arr[u].pos-arr[ch[arr[u].gr].hd].pos);
    gr[arr[u].gr].cnt=arr[v].pos-arr[u].pos+1;
    split(root[arr[u].gr],b,gr[arr[u].gr].r,gr[arr[u].gr].cnt);
    
    // cout<< "mid b4 swap: "<<'\n';
    // printtree(b);
    // cout<<'\n';

    if(swp && b) b->rev^=1;

    // cout<< "mid: "<<'\n';
    // printtree(b);
    // cout<<'\n';

    merge(t,t,b);
    merge(t,t,c);

    // cout<< "tree: "<<'\n';
    // printtree(t);
    // cout<<'\n';

    if(t) t->rev^=1;
    
    // cout<< "rev tree: "<<'\n';
    // printtree(t);
    // cout<<'\n';
    c=NULL;
    int x;
    // cout<< swp <<'\n';
    for(int i=2;i>=0;i--){
        if(i<2){
            for(int j=part[i].size()-1;j>=0;j--){
                x=part[i][j];
                if(!t) continue;
                split(t,t,c,(t->sz)-gr[x].cnt);
                if(swp && i==1 && c) c->rev^=1; 
                // cout<< i<< " " << j <<" "<<x<<" " <<": "<<'\n';
                // printtree(c);
                // cout<<'\n';
                merge(root[x],gr[x].l,c);
                merge(root[x],root[x],gr[x].r);
            }
        }else{
            for(int j=0;j<part[i].size();j++){
                x=part[i][j];
                if(!t) continue;
                split(t,t,c,(t->sz)-gr[x].cnt); 
                // cout<< i<< " " << j <<" "<<x<<" " <<": "<<'\n';
                // printtree(c);
                // cout<<'\n';
                merge(root[x],gr[x].l,c);
                merge(root[x],root[x],gr[x].r);
            }
        }
    }
    part[0].clear();
    part[1].clear();
    part[2].clear();
}
void getsum(int u,int v){
    ans=0;
    int anc=lca(u,v);
    // printf("%d %d %d\n",anc,u,v);
    while(arr[u].gr!=arr[anc].gr){
        gr[arr[u].gr].cnt=arr[u].pos-arr[ch[arr[u].gr].hd].pos+1;
        split(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r,gr[arr[u].gr].cnt);
        if(root[arr[u].gr]) ans+=root[arr[u].gr]->sum;
        // printf("%d %d\n",arr[u].gr,root[arr[u].gr]->sum);
        merge(root[arr[u].gr],root[arr[u].gr],gr[arr[u].gr].r);
        u=pa[0][ch[arr[u].gr].hd];
    }
    while(arr[v].gr!=arr[anc].gr){
        gr[arr[v].gr].cnt=arr[v].pos-arr[ch[arr[v].gr].hd].pos+1;
        // printf("%d\n",gr[arr[v].gr].cnt);
        split(root[arr[v].gr],root[arr[v].gr],gr[arr[v].gr].r,gr[arr[v].gr].cnt);
        if(root[arr[v].gr]) ans+=root[arr[v].gr]->sum;
        // printf("%d %d\n",arr[v].gr,root[arr[v].gr]->sum);
        merge(root[arr[v].gr],root[arr[v].gr],gr[arr[v].gr].r);
        v=pa[0][ch[arr[v].gr].hd];
    }
    a=NULL;
    if(arr[u].pos>arr[v].pos) swap(u,v);
    split(root[arr[u].gr],gr[arr[u].gr].l,root[arr[u].gr],arr[u].pos-arr[ch[arr[u].gr].hd].pos);
    gr[arr[u].gr].cnt=arr[v].pos-arr[u].pos+1;
    split(root[arr[u].gr],a,gr[arr[u].gr].r,gr[arr[u].gr].cnt);
    if(a) ans+=a->sum;
    // printf("%d %d\n",arr[v].gr,a->sum);
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
    dfs(1,0);
    hld(1);
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

15 3
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2
2 3
3 4
4 5
6 4
2 7
7 8
7 9
2 10
1 11
11 12
12 13 
12 14
11 15
S 2 12
R 14 9
S 8 15
*/