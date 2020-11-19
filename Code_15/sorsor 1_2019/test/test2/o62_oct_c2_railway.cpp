/*
    TASK:o62_oct_c2_railway
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w,i;
    bool operator <(const A &o) const{
        return w<o.w;
    }
};
A g[200010];
int p[100010],mark[200010],ans[200010];
vector< int > mst,ou;
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,a,b,c,tu,tv,tw,ti,mi=1e9,ma=-1e9,ru,rv,ch=-1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&g[i].u,&g[i].v,&g[i].w);
        g[i].i=i;
    }
    int cnt=0,w=0;
    for(int i=1;i<=n;i++)p[i]=i;
    sort(g+1,g+1+m);
    for(int i=1;i<=m;i++){
        // printf("sort : %d %d %d %d\n",g[i].u,g[i].v,g[i].w,g[i].i);
        if(g[i].i<n){
            p[fin(g[i].u)]=fin(g[i].v);
        }
        else{
            // printf("%d\n",g[i].i);
            if(fin(g[i].u)==fin(g[i].v)){
                // printf("clear");
                continue;
            }
            ch=-1;
            for(int j=i+1;j<=m;j++){
                if(g[j].i>=n){
                    // printf("- %d\n",g[j].i);
                    if(fin(g[j].u)==fin(g[j].v)){
                        // printf("here : %d\n",g[j].i);
                        ch=1;
                        ans[g[i].i]=g[j].w;
                        ans[g[j].i]=g[i].w;
                        swap(g[j].i,g[i].i);
                        swap(g[j].u,g[i].u);
                        swap(g[j].v,g[i].v);
                        break;
                    }
                }
            }
            if(ch==-1){
                printf("0\n");
                return 0;
            }
        }
    }
    printf("1\n");
    for(int i=n;i<=m;i++){
        printf("%d\n",ans[i]);
    }
}