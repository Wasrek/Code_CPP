/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int sum[100010],p[1000010];
struct A{
    int i,t,v;
    bool operator<(const A & o) const{
        return t>o.t;
    }
};
priority_queue< A > h;
int fin(int i){
    if(p[i]==i) return i;
    return fin(p[i]);
}
void upd(int now,int targ){
    sum[now]-=sum[targ];
    if(p[now]==now) return ;
    upd(p[now],targ);
}
int main()
{
    int n,m,f,u,v,t,w,now,rv,ru;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]);
        p[i]=i;
    }
    for(int tt=1;tt<=m;tt++){
        scanf("%d",&f);
        while(!h.empty() && h.top().t==tt){
            sum[fin(h.top().i)]+=h.top().v;
            h.pop();
        }
        if(f==1){
            scanf("%d",&u);
            if(p[u]==u) continue;
            upd(p[u],u);
            p[u]=u;
        }else if(f==2){
            scanf("%d %d %d %d",&u,&v,&t,&w);
            rv=fin(v);
            if(rv==u) continue;
            if(p[u]!=u){
                upd(p[u],u);
            }
            p[u]=rv;
            sum[rv]+=sum[u];
            h.push({u,t,w});
        }else if(f==3){
            scanf("%d",&v);
            rv=fin(v);
            printf("%d\n",sum[rv]);
        }
    }
    return 0;
}
/*
7 17
1 2 3 4 5 6 7
2 1 2 5 1
2 2 5 5 2
2 3 5 5 3
2 4 5 8 4
3 1
2 6 7 8 5
2 5 7 8 6
3 1
3 6
2 7 1 11 7
3 7
2 2 5 13 8
3 1
3 4
2 4 6 17 10
1 4
3 4
*/