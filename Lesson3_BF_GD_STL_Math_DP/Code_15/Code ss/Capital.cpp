/*
    TASK:Capital
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int y,w;
};
vector< A > g[100010];
int in[100010],w[100010],mark[100010],maa=0;
void dfs(int i,int ww,int f){
    for(auto x: g[i]){
        if(x.y==f)continue;
        if(w[x.y]<ww+x.w){
            w[x.y]=ww+x.w;
            maa=max(maa,w[x.y]);
            dfs(x.y,ww+x.w,i);
        }
    }
}
int main()
{
    int n,x,y,z,tu,tw,i,nn;
    scanf("%d",&n);
    nn=n;
    n--;
    while(n--){
        scanf("%d %d %d",&x,&y,&z);
        g[x].push_back({y,z});
        g[y].push_back({x,z});
        in[x]++;
        in[y]++;
    }
    dfs(1,0,-1);
    printf("%d\n",maa);
}
