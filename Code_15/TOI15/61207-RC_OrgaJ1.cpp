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
        memset(mark,0,sizeof mark);
        scanf("%d %d",&a,&b);
        h.push({a,0});
        mark[a]=1;
        while(!h.empty()){
            i=h.top().i;
            w=h.top().w;
            h.pop();
            //printf("%d %d\n",i,w);
            if(i==b){
                printf("%d\n",w);
                break;
            }
            for(auto x:g[i]){
                if(mark[x])continue;
                mark[x]=1;
                if(x>n){
                    h.push({x,w+1});
                }else h.push({x,w});
            }
        }
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
