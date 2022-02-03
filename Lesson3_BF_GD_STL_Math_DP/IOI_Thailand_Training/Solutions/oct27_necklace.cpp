/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
};
A a[300010];
int ta[300010],p[300010];
int fr(int i){
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}
int main()
{
    int n,l,r,u,v,x,y;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d %d",&r,&l);
        if(!p[r]) p[r]=ta[r]=r,a[r]={r,r};
        if(!p[l]) p[l]=ta[l]=l,a[l]={l,l};
        u=l;v=a[l].r;
        x=r;y=ta[fr(r)];
        a[u].r=x;a[x].l=u;
        if(v!=u){a[v].l=y;a[y].r=v;}
        else{
            ta[fr(l)]=y;
        }
        p[fr(r)]=fr(l);
    }
    int i=fr(1);
    printf("%d ",i);
    while(a[i].r!=i){
        printf("%d ",a[i].r);
        i=a[i].r;
    }
    return 0;
}