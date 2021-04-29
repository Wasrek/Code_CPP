/*
    TASK:o57_mar_c3_lego
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
struct Node{
    int prio,v,sz;
    struct Node *l,*r;
    Node(int val){
        prio = rand();
        v = val;
        sz=1;
        l=r=NULL;
    }
};
typedef Node* pnode;
int arr[N];
int sz(pnode t){
    return t? t->sz : 0;
}
void upd_sz(pnode t){
    if(t)t->sz=sz(t->l)+sz(t->r)+1;
}
void merge(pnode &t,pnode l,pnode r){
    // t - result   merge between l and r
    if(!l || !r) t= l? l:r;
    else if(l->prio > r->prio) t=l,merge(t->r,l->r,r);
    else t=r,merge(t->l,l,r->l);
    upd_sz(t);
}
void split(pnode t,pnode &l,pnode &r,int k){
    if(!t) return void(l=r=NULL);
    int npos=sz(t->l)+1;
    if(npos<=k){//go left
        l=t;
        split(l->r,l->r,r,k-npos);
    }else{//go right
        r=t;
        split(r->l,l,r->l,k);
    }
    upd_sz(t);
}
int dfs(pnode now,int k){
    int npos=sz(now->l)+1;
    if((!now->l && !now->r) || npos==k) return now->v;
    if(k<=npos){// on left side
        return dfs(now->l,k);
    }else{
        return dfs(now->r,k-npos);
    }
}
int main()
{
    srand(time(NULL));
    pnode root,lg1,lg2,lg3;
    root=lg1=lg2=lg3=NULL;
    int n,m,k,q,a,l,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        // add to the first tree --> merge(a[1]..a[i-1],a[i])
        merge(root,root,new Node(arr[i]));
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&q);
        if(q==1){
            scanf("%d %d %d",&a,&l,&b);
            // split lg1->arr[1]...arr[a-1]   lg2->arr[a]...arr[a+l-1]   lg3->arr[a+l]..arr[n]
            // merge lg1 and lg3
            // if b>=a+l >> is the part og lg3 position of b will change to b-l
            // split lg1 and lg3 into lg1->arr[1]...arr[b-1] lg3->arr[b-l]...arr[n-l] (according to position after merge lg1 & lg3)
            // merge lg1 + lg2 + lg3
            split(root,lg1,lg2,a-1);
            split(lg2,lg2,lg3,l);
            merge(lg1,lg1,lg3);
            if(b>=a+l) b-=l;
            split(lg1,lg1,lg3,b-1);
            merge(root,lg1,lg2);
            merge(root,root,lg3);
        }else{
            scanf("%d",&k);
            printf("%d\n",dfs(root,k));
        }
    }
    return 0;
}