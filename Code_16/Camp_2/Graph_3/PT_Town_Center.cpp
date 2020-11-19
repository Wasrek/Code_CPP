/*
    TASK:PT_Town Center
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
int dis[1010][1010],p[1010],deg[1010];
int fin(int i) {
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
priority_queue< A > h;
int main()
{
    int q,n,w,pi,pj,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            p[i]=i;
            deg[i]=0;
            for(int j=1;j<=n;j++){
                scanf("%d",&now);
                if(now && i<j) h.push({i,j,now});
            }
        }
        while(!h.empty()){
            int i=h.top().i;
            int j=h.top().j;
            h.pop();
            pi=fin(i);
            pj=fin(j);
            if(pi==pj) continue;
            deg[i]++;
            deg[j]++;
            p[pi]=pj;
        }
        int ma=0,ans;
        for(int i=1;i<=n;i++){
            if(deg[i]>ma){
                ma=deg[i];
                ans=i;
            }
        }
        printf("%d %d\n",ans,ma);
    }
    return 0;
}