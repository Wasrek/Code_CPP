/*
    TASK:RC_Tree Send
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
vector<int>g[300010];
priority_queue< A >q;
int mark[300010],dis[300010];
int main(){
    int n,a,b,m,x,y,cou=0,ii,ww,i,j;
    scanf("%d %d %d",&n,&a,&b);
    m=n-1;
    while(m--){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    q.push({a,0});
    q.push({b,0});
    mark[a]=mark[b]=1;
    for(i=1;i<=n;i++)dis[i]=1e9;
    dis[a]=dis[b]=0;
    cou=2;
    while(!q.empty()){
        ii=q.top().i;
        ww=q.top().w;
        j=0;
        q.pop();
        for(auto x:g[ii]){
            if(dis[x]>j+1)dis[ii]=++j,cou++,q.push({x,j});
        }
    }
    int sum=0;
    for(i=1;i<=n;i++){
        sum+=dis[i];
    }
    printf("%d\n",sum);
}
/*
10 1 2
1 2
2 5
1 3
1 4
4 6
6 7
3 8
3 9
3 10
*/
