#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,k;
    bool operator < (const A & o)const{
        return w > o.w;
    }
};
priority_queue < A> dijk;
A temp;
int dis[5050][110],mark[5050][110];
vector < A> g[5050];
int main()
{
    int n,m,k,i,j,s,nowu,noww,nowk,mi;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&s,&temp.v,&temp.w);
        temp.k = 0;
        g[s].push_back(temp);
        swap(s,temp.v);
        g[s].push_back(temp);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            dis[i][j] = 1<<20;
        }
    }
    dis[1][0] = 0;
    //mark[1][0] = 1;
    temp.v = 1;
    temp.w = 0;
    temp.k = 0;
    dijk.push(temp);
    while(!dijk.empty()){
        temp = dijk.top();
        dijk.pop();
        nowu = temp.v;
        noww = temp.w;
        nowk = temp.k;
        for(i=0;i<g[nowu].size();i++){
            if(noww + g[nowu][i].w < dis[g[nowu][i].v][nowk]){
                dis[g[nowu][i].v][nowk] = noww + g[nowu][i].w;
                temp.v = g[nowu][i].v;
                temp.w = dis[g[nowu][i].v][nowk];
                temp.k = nowk;
                //mark[g[nowu][i].v][nowk] = 1;
                dijk.push(temp);
            }
            if(noww + g[nowu][i].w/2 < dis[g[nowu][i].v][nowk+1]){
                dis[g[nowu][i].v][nowk+1] = noww + g[nowu][i].w/2;
                temp.v = g[nowu][i].v;
                temp.w = dis[g[nowu][i].v][nowk+1];
                temp.k = nowk+1;
                //mark[g[nowu][i].v][nowk+1] = 1;
                dijk.push(temp);
            }
        }
    }
    printf("%d\n",dis[n][0]);
    mi = dis[n][0];
    for(i=1;i<=k;i++){
        mi = min(mi,dis[n][i]);
    }
    printf("%d\n%d\n",mi,dis[n][0]-mi);
    return 0;
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
