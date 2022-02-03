/*
    TASK:48_Bicycle
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int p[60000];
struct A{
    int u,v,w;
    bool operator <(const A &o) const{
        return w<o.w;
    } 
};
priority_queue< A > h;
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]= fin(p[i]);
}
int main()
{
    int q,n,m,u,v,w,hu,hv,hw;
    long long ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&u);
            mp[u]=i;
            p[i]=i;
        }
        ans=0;
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            h.push({mp[u],mp[v],w});
        }
        while(!h.empty()){
            hu=h.top().u;
            hv=h.top().v;
            hw=h.top().w;
            h.pop();
            hu=fin(hu);
            hv=fin(hv);
            if(hu!=hv){
                p[hu]=hv;
            }else{
                ans+=hw;
            }
        }
        printf("%lld\n",ans);
        mp.clear();
    }
    return 0;
}
/*
2
8 10
1 2 3 4 5 6 7 8
1 2 3
1 5 5
2 3 4
2 6 3
3 4 2
3 7 5
4 8 5
5 6 2
6 7 7
7 8 3
14 18
5 11 13 0 3 8 6 2 12 14 1 9 10 4
5 0 2
5  6 7
5 10 7
11 6  5
11 10 9
11 12 4
13 14 3
13 8 5
13 12 6
0 1 7
3 2 7
3 8 1
3 4 1
8 9 1
6 1 7
2 1 9
14 9 1
9 4 3
*/