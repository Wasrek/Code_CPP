/*
    TASK:Technology
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int lvl[100100],in[100100],go[100100],ma[100100],ml[100100],cl[10010],in1[100100];
struct A{
    int i,ml;
    bool operator <(const A& o) const{
        return ml>o.ml;
    }
};
priority_queue< A >h;
vector< int > g[100100];
queue< int > q;
stack< int > st;
void dfs(int i){
    ma[i]=1;
    ml[i]=lvl[i];
    for(auto x: g[i]){
        if(!ma[x] && go[x]) dfs(x);
        if(ma[x]) ml[i]=min(ml[i],ml[x]);
    }
    if(!in1[i]) h.push({i,ml[i]});
}
int main()
{
    int n,k,t,m,now,ans=0;
    scanf("%d %d %d",&n,&k,&t);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&lvl[i],&m);
        cl[lvl[i]]++;
        in1[i]=in[i]=m;
        if(!in[i]) q.push(i);
        while(m--){
            scanf("%d",&now);
            g[now].push_back(i);
        }
    }
    while(!q.empty()){
        now=q.front();
        q.pop();
        go[now]=1;
        st.push(now);
        for(auto x:g[now]){
            if(go[x]) continue;
            in[x]--;
            if(!in[x])q.push(x);
        }
    }
    while(!st.empty()){
        now=st.top();
        st.pop();
        if(!ma[now]) dfs(now);
    }
    while(!h.empty() && t--){
        now=h.top().i;
        h.pop();
        cl[lvl[now]]--;
        for(auto x: g[now]){
            in1[x]--;
            if(!in1[x]) h.push({x,ml[x]});
        }
    }
    // for(int i=1;i<=k;i++) printf("%d ",cl[i]);
    // printf("\n");
    for(int i=1;i<=k;i++){
        if(cl[i]){
            now=i-1;
            break;
        }
    }
    if(!now) printf("-1");
    else printf("%d\n",now);
    return 0;
}
/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1
*/