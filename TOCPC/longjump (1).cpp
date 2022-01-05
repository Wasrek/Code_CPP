#include<bits/stdc++.h>
using namespace std;
int pi[100010],pj[100010];
map<pair<int,int>,int> val;
vector<int> gi[1000010],gj[1000010];
queue<pair<int,int>> bfs;
int main(){
    int i,j,n,m,k,si,sj,ei,ej;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d %d %d",&si,&sj,&ei,&ej);
    for(i=1;i<=k;i++){
        scanf("%d %d",&pi[i],&pj[i]);
        gi[pi[i]].push_back(pj[i]);
        gj[pj[i]].push_back(pi[i]);
    }
    for(i=1;i<=n;i++){
        gi[i].push_back(0);
        gi[i].push_back(m+1);
        sort(gi[i].begin(),gi[i].end());
    }
    for(i=1;i<=m;i++){
        gj[i].push_back(0);
        gj[i].push_back(n+1);
        sort(gj[i].begin(),gj[i].end());
    }
    bfs.push({ei,ej});
    val[{ei,ej}]=1;
    while(!bfs.empty()){
        i=bfs.front().first;
        j=bfs.front().second;
        bfs.pop();
        int u,l,r,d,ii,jj;
        ii=lower_bound(gi[i].begin(),gi[i].end(),j)-gi[i].begin();
        u=gi[i][ii]-1;
        d=gi[i][ii-1]+1;
        jj=lower_bound(gj[j].begin(),gj[j].end(),i)-gj[j].begin();
        r=gj[j][jj]-1;
        l=gj[j][jj-1]+1;
        if(val[{i,u}]==0) bfs.push({i,u}),val[{i,u}]=val[{i,j}]+1;
        if(val[{i,d}]==0) bfs.push({i,d}),val[{i,d}]=val[{i,j}]+1;
        if(val[{l,j}]==0) bfs.push({l,j}),val[{l,j}]=val[{i,j}]+1;
        if(val[{r,j}]==0) bfs.push({r,j}),val[{r,j}]=val[{i,j}]+1;
    }
    printf("%d\n",val[{si,sj}]-1);
return 0;
}
