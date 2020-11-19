/*
    TASK:Cable Car TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
    if(w!=o.w) return w<o.w;
    }
};
int p[2600];
priority_queue< A > h;
int fin(int i){
if(p[i]==i)return i;
else return p[i]=fin(p[i]);
}
int main(){
    int n,m,u,v,w,i,pu,pv;
    int ans;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        h.push({u,v,w});
    }
    scanf("%d %d %d",&u,&v,&w);
    for(i=1;i<=n;i++)p[i]=i;
    while(!h.empty()){
        pu=fin(h.top().u);
        pv=fin(h.top().v);
        if(pu!=pv){
            p[pu]=pv;
        }
        if(fin(u)==fin(v)){
            ans=h.top().w;
            n=w/(ans-1);
            if(w%(ans-1)!=0){
                printf("%d\n",n+1);
            }else{
                printf("%d",n);
            }
            return 0;
        }
        h.pop();
    }
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/
