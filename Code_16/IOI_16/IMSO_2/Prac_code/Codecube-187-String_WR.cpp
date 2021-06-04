#include<bits/stdc++.h>
using namespace std;
struct node{
    char a;
    int sz,prio,lz;
    node *l,*r;
    node(char c){
        a=c;
        sz=1;
        prio=rand();
        lz=0;
        l=r=NULL;
    }
};
typedef node* pnode;
int sz(pnode t){
    return t ? t->sz : 0;
}
void upd(pnode t){
    if(t) t->sz = sz(t->l)+sz(t->r)+1;
}
void updlz(pnode t){
    if(!t || !t->lz) return ;
    if(t->lz){
        swap(t->l,t->r);
        if(t->l) t->l->lz^=1;
        if(t->r) t->r->lz^=1;
        t->lz=0;
    }
}
void split(pnode t,pnode &l,pnode &r,long long p){
    if(!t) {
        l=r=NULL;
        return;
    }
    int cntl;
    updlz(t);
    cntl=sz(t->l)+1;
    if(cntl<=p){
        l=t;
        split(l->r,l->r,r,p-cntl);
    }
    else {
        r=t;
        split(r->l,l,r->l,p);
    }
    upd(t);
}
void merge(pnode &t,pnode l,pnode r){
    updlz(l);
    updlz(r);
    if(!l || !r) t= l? l:r;
    else if(l->prio > r->prio) t=l,merge(t->r,l->r,r);
    else t=r,merge(t->l,l,r->l);
    upd(t);
}
char s[100010],T,add[100010];
int l,r;
pnode root,radd,r1,r2,r3;
void print(pnode t){
    if(!t) return ;
    updlz(t);
    if(t->l){
        print(t->l);
    }
    printf("%c",t->a);
    if(t->r){
        print(t->r);
    }
}
int main(){
    int i,n,q,p,m;
    scanf(" %s",s);
    n=strlen(s);
    for(i=0;i<n;i++){
        merge(root,root,new node(s[i]));
    }
    scanf("%d",&q);
    while(q--){
        scanf(" %c",&T);
        if(T=='I'){
            scanf(" %d %s",&p,add);
            m=strlen(add);
            radd=NULL;
            for(i=0;i<m;i++){
                merge(radd,radd,new node(add[i]));
            }
            split(root,r1,r2,p);
            merge(root,r1,radd);
            merge(root,root,r2);
        }else{
            scanf("%d %d",&l,&r);
            split(root,r2,r3,r);
            split(r2,r1,r2,l-1);
            if(r2) r2->lz^=1;
            merge(r1,r1,r2);
            merge(root,r1,r3);
        }
    }
    print(root);
return 0;
}
