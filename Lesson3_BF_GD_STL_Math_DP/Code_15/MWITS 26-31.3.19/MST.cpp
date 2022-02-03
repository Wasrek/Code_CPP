/*
    TASK:MST
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    double w;
    bool operator<(const A&o)const{
    return w>o.w;
    }
};
int p[1010];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
priority_queue< A >h;
int main(){
    int n,m,tu,tv,i,u,v;
    double ans=0,w,tw;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %lf",&u,&v,&w);
        h.push({u,v,w});
    }
    for(i=1;i<=n;i++)p[i]=i;
    while(!h.empty()){
        tu=h.top().u,tv=h.top().v,tw=h.top().w;h.pop();
        if(fin(tu)!=fin(tv)){
            p[fin(tu)]=fin(tv);
            ans+=tw;//printf("%.3lf",ans);
        }
    }
    printf("%.3f",ans);
}
/*
4 4
0 1 1
1 2 1
2 3 1
3 0 2
*/
