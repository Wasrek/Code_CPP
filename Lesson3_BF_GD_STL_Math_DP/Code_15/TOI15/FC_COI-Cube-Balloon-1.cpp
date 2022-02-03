/*
    TASK:FC_COI Cube Balloon
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,v,t;
    bool operator <(const A& o)const{
    return t>o.t;
    }
};
int p[100010],dp[100010];
int fin(int i){
    if(p[i]==i)return i;
    else return fin(p[i]);
}
priority_queue< A >h;
int main(){
    int n,m,i,f,a,b,t,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&dp[i]),p[i]=i;
   for(i=1;i<=m;i++){
        while(!h.empty() && h.top().t==i){
            dp[fin(h.top().a)]+=h.top().v;
            h.pop();
        }
        scanf("%d",&f);
        if(f==1){
            scanf("%d",&a);
            int pa,d,aa;
            pa = fin(a);
            d = dp[a];
            aa = a;
            while(p[aa]!=aa){
                dp[p[aa]]-=d;
                aa = p[aa];
            }
            p[a]=a;
        }
        else if(f==2){
            scanf("%d %d %d %d",&a,&b,&t,&v);
            int pa,pb,d,aa;
            pa = fin(a);
            pb = fin(b);
            if(a!=pb){
                d = dp[a];
                aa = a;
                while(p[aa]!=aa){
                    dp[p[aa]]-=d;
                    aa = p[aa];
                }
                p[a] = pb;
                dp[pb] += dp[a];
                h.push({a,v,t});
            }
        }else{
            scanf("%d",&a);
            printf("%d\n",dp[fin(a)]);
        }
    }
    return 0;
}
