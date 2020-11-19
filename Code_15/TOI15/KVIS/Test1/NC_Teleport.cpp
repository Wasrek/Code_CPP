/*
    TASK:NC_Teleport
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dist[101005];
queue<pair<int,int>>q;
vector<int> g[101005];
int main(){
    int n,a,t,i,j,num;
    scanf("%d %d %d",&n,&a,&t);
    for(i=2;i<=n+t;i++)dist[i]=1e9;
    for(i=1;i<=t;i++){
        for(j=1;j<=a;j++){
            scanf("%d",&num);
            g[i+n].push_back(num);
            g[num].push_back(i+n);
        }
    }
    q.push({1,0});
    while(!q.empty()){
        int nowi=q.front().first,noww=q.front().second;q.pop();
        if(nowi==n){
            printf("%d\n",noww/2+1);
            return 0;
        }
        for(auto &x:g[nowi])
        {
            if(noww+1<dist[x])dist[x]=noww+1,q.push({x,dist[x]});
        }
    }
    printf("-1\n");
    return 0;
}

