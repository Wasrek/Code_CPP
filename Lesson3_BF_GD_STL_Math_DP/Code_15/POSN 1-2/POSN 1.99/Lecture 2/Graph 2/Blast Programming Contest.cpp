/*
    TASK:Blast Programming Contest
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
/*
#include<bits/stdc++.h>
using namespace std;
struct A{
    int j,w;
};
vector<int> a[65];
queue<A> q;
int mark[65];
int main(){
    int m,s,e,x,y;
    scanf("%d %d %d",&m,&s,&e);
    while(m--){
        scanf("%d %d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    q.push({s,0});
    int i,j,w;
    while(!q.empty()){
        j=q.front().j,w=q.front().w;
        q.pop();
        if(j==e){printf("%d\n",w);return 0;}
        for(i=0;i<a[j].size();i++){
            if(mark[a[j][i]]==0){
                mark[a[j][i]]=1;
                q.push({a[j][i],w+1});
            }
        }
    }
}

9 4 30
4 6
4 20
6 7
6 8
7 9
9 10
10 21
21 30
21 25


Floyd-Warshall Algorithm
find all pairs shortest path(dp)
*/
#include<bits/stdc++.h>
using namespace std;
int dis[100][100];
int main()
{
    int i,j,k,m,s,e,u,v;
    scanf("%d %d %d",&m,&s,&e);
    for(i=1; i<=60; i++)
        for(j=1; j<=60; j++)
            if(i!=j)
                dis[i][j]=1<<20;
    while(m--)
    {
        scanf("%d %d",&u,&v);
        dis[u][v]=dis[v][u]=1;
    }
    for(k=1; k<=60; k++)
        for(i=1; i<=60; i++)
            for(j=1; j<=60; j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    printf("%d\n",dis[s][e]);
    return 0;
}
