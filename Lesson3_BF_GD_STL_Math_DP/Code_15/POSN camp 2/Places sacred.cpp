/*
    TASK:Places sacred
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator< (const A&o) const{
        if(w!=o.w)return w<o.w;
    }
};
priority_queue< A > h;
int p[200100];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main(){
    int n,m,i,pu,pv,u,v,w;
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        w--;
        h.push({u,v,w});
    }
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    while(!h.empty()){
        pu=fin(h.top().u);pv=fin(h.top().v);
        if(pu!=pv){
            ans+=h.top().w;p[pu]=pv;
        }
        h.pop();
    }
    printf("%lld",ans);
}
/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/
