/*
    TASK:o58_apr22_shufnum
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v,prio,lz;
    struct Node *l,*r;
    Node(int val){
        v=val;
        prio=rand();
        lz=0;
        l=r=NULL;
    }
};
typedef Node* pnode;
void upd_lz(pnode t){
    if(!t || !t->lz) return ;
    t->v += t->lz;
    if(t->l) t->l->lz+=t->lz;
    if(t->r) t->r->lz+=t->lz;
    t->lz=0;
    return ;
}
void merge(pnode &t,pnode l,pnode r){
    upd_lz(l); upd_lz(r);
    if(!l || !r) t= l? l: r;
    else if(l->prio > r->prio) t=l,merge(t->r,l->r,r);
    else t=r,merge(t->l,l,r->l);
    return ;
}
int qy(pnode t,int a){
    if(!t) return 0;
    upd_lz(t);
    if((!t->l && !t->r) || (t->v==a)) return t->v==a? 1:0;
    if(a<=t->v) return qy(t->l,a);
    else return qy(t->r,a);
}
void split(pnode t,pnode &l,pnode &r,int k){
    if(!t) return void(l=r=NULL);
    upd_lz(t);
    if(t->v <= k) l=t,split(t->r,t->r,r,k);
    else r=t,split(t->l,l,t->l,k);
}
int main()
{
    srand(time(NULL));
    pnode root,l,r;
    root=l=r=NULL;
    int n,q,a,p1,p2,opr;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        merge(root,root,new Node(a));
    }
    for(int i=1;i<=q;i++){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d",&a);
            printf("%d\n",qy(root,a));
        }else{
            scanf("%d %d %d",&a,&p1,&p2);
            if(!qy(root,a)) continue;
            split(root,l,r,a-1);
            if(l)l->lz+=p1;
            if(r)r->lz+=p2;
            merge(root,r,l);
        }
    }
    return 0;
}
/*
6 8
1 2 4 5 20 22
1 1
2 5 25 0
1 1
2 21 10 -30
2 27 1 -29
1 21
2 0 31 1
1 29
*/