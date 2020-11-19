/*
    TASK:RC_Organization of Justice1
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
vector<int>g[200010];
int mark[200010];
priority_queue< A > h;
int main(){
    int n,m,i,j,p,a,b,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&p);
        for(j=1;j<=p;j++){
            scanf("%d",&a);
            g[i+n].push_back(a);
            g[a].push_back(i+n);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        memset(mark,127,sizeof mark);
        scanf("%d %d",&a,&b);
        h.push({a,0});
        mark[a]=0;
        while(!h.empty()){
            i=h.top().i;
            w=h.top().w;
            h.pop();
            //printf("%d %d\n",i,w);
            for(auto x:g[i]){
                if(x>n && mark[x]<=w+1)continue;
                if(x<=n && mark[x]<=w)continue;
                if(x>n){
                    mark[x]=w+1;
                    h.push({x,w+1});
                }else mark[x]=w,h.push({x,w});
            }
        }
        printf("%d\n",mark[b]);
    }
}
/*
9 3
4
1 2 3 4
3 4 5 6
4 6 7 8 9
4
1 9
2 7
4 1
2 5
*/
