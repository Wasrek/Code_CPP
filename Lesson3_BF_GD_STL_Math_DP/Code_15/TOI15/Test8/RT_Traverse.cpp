/*
    TASK:RT_Traverse
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,n,bm;
};
vector<int> g[10];
queue<A > q;
int main(){
    int n,m,a,b,i,bm,w,cou=0,u;
    scanf("%d %d",&n,&m);
    while(m--){
       scanf("%d %d",&a,&b);
       g[a].push_back(b);
       g[b].push_back(a);
    }
    q.push({-1,1,1});
    while(!q.empty()){
        i=q.front().n;
        bm=q.front().bm;
        u=q.front().u;
        //printf("%d %d\n",i,bm);
        q.pop();
        if(bm==(1<<n)-1)cou++;
        for(auto x: g[i]){
            if(u==x)continue;
            if(bm & (1<<(x-1)))continue;
            //printf("- %d\n",(1<<(x-1)));
            q.push({i,x,(bm|(1<<(x-1)))});
        }
    }
    printf("%d\n",cou);
}
