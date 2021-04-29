/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v,sz,prio,rev;
    struct Node *l,*r;
    Node(int val){
        v=val;
        sz=1;
        rev=0;
        prio=rand();
        l=r=NULL;
    }
};
typedef Node* pnode;
int sz(pnode t){
    return t? t->sz:0;
}
void upd_sz(pnode t){
    if(t) t->sz=1+sz(t->l)+sz(t->r);
}
void opr(pnode t){
    if(!t || !t->rev) return ;
    swap(t->r,t->l);
    if(t->l) t->l->rev^=1;
    if(t->r) t->r->rev^=1;
    t->rev=0;
    return ;
}
void merge(pnode &t,pnode l,pnode r){
    opr(l);opr(r);
    if(!l || !r) t= l ? l:r;
    else if(l->prio > r->prio) t=l,merge(t->r,l->r,r);
    else t=r,merge(t->l,l,r->l);
    upd_sz(t);
    return ;
}
void split(pnode t,pnode &l,pnode &r,int k){
    if(!t) return void(l=r=NULL);
    opr(t);
    int cur_pos=sz(t->l)+1;
    if(cur_pos<=k) l=t,split(t->r,t->r,r,k-cur_pos);
    else r=t,split(t->l,l,r->l,k);
    upd_sz(t);
    return ;
}
void dfs(pnode t){
    if(!t) return ;
    opr(t);
    dfs(t->l);
    printf("%d ",t->v);
    dfs(t->r);
    return ;
}
int main()
{
    srand(time(NULL));
    pnode root,x,y,z;
    root=x=y=z=NULL;
    int n,m,a,b,c; 
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        merge(root,root,new Node(i));
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        split(root,x,y,a); // x  y
        split(y,y,z,b); // x y z
        merge(x,x,z); // y (x+z)
        split(x,x,z,c);// x y z
        y->rev=1;
        merge(y,y,z);
        merge(root,x,y);
    }
    dfs(root);
    return 0;
}

// 10 2
// 6 2 2
// 5 3 6

// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 4 5 6     7 8 9 10
// 1 2 3 4 5 6     7 8    9 10
// 7 8    1 2 3 4 5 6 9 10
// 7 8     1 2    3 4 5 6 9 10
// 1 2     8 7 3 4 5 6 9 10    

// 1 2 8 7 3 4 5 6 9 10

// 1 2 8 7 3   4 5 6    9 10
// 4 5 6    1 2 8 7 3 9 10
// 4 5 6    1 2 8 7 3 9    10
// 6 5 4 10   1 2 8 7 3 9
// 1 2 8 7 3 9   6 5 4 10
// 1 2 8 7 3 9 6 5 4 10


//           4
//     2          6
// 1      3    5      7
  
//           4
//     6          2
// 5      7    1      3

//           4
//     6          2
// 7      5    3      1

 