/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int x[100010],t[100100],re[1000010],p[100010];
priority_queue< int > h;//time -1
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,k,q,a,b,v;
    scanf("%d %d %d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        p[i]=i;
        scanf("%d",&x[i]);
        re[x[i]]=i;
        h.push(-x[i]);
    }
    t[0]=h.top()*-1;
    for(int i=1;i<=k;i++){
        scanf("%d %d",&a,&b);
        if(x[fin(a)]<x[fin(b)]) swap(a,b);// parent = max x
        p[fin(b)]=fin(a);
        while(!h.empty() && fin(re[h.top()*-1])!=re[h.top()*-1]) h.pop();
        t[i]=h.top()*-1;
    }
    // for(int i=0;i<=k;i++) printf("%d ",t[i]);
    int lb;
    for(int i=1;i<=q;i++){
        scanf("%d",&v);
        lb=lower_bound(t,t+k+1,v)-t;
        if(lb>k) printf("-1\n");
        else printf("%d\n",lb);
    }
    return 0;
}