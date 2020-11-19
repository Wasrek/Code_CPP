/*
    TASK:Places Sacred
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o) const{
    return w<o.w;
    }
};
int p[200100];
priority_queue< A > h;
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,m,s,e,w,i;
    long long ans=0;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&s,&e,&w);
        w--;
        h.push({s,e,w});
    }
    for(i=1;i<=n;i++)p[i]=i;
    while(!h.empty()){
        s=h.top().i;
        e=h.top().j;
        w=h.top().w;
        h.pop();
        if(fin(s)!=fin(e)){
            ans+=w;
            p[fin(s)]=fin(e);
        }
    }
    printf("%lld\n",ans);
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
