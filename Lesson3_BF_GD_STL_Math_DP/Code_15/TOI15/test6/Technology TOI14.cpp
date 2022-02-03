/*
    TASK:Technology TOI14
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,t;
    bool operator<(const A&o)const{
    return t>o.t;
    }
};
vector<int> g[100010];
priority_queue< A >h;
queue<int> q;
stack<int> st;
int in[100010],in1[100010],tec[100010],a[100010],mark[100010],cango[100010],lvl[100010],ma[100010];
void dfs(int i){
    ma[i]=1;
    for(auto x: g[i]){
        if(cango[i] && !ma[i])dfs(i);
        if(ma[x])lvl[i]=min(lvl[i],lvl[x]);
    }
}
int main(){
    memset(lvl,127,sizeof lvl);
    int n,t,k,i,p,v,tn,tt,ans;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        lvl[i]=a[i];
        scanf("%d",&p);
        in[i]=in1[i]=p;
        if(!in[i]){
            q.push(i);
        }
        tec[a[i]]++;
        while(p--){
        scanf("%d",&v);
        g[v].push_back(i);
        }
    }
    while(!q.empty()){
        i=q.front();
        q.pop();
        cango[i]=1;
        st.push(i);
        for(auto x:g[i]){
            in1[x]--;
            if(!in1[x])q.push(x);
        }
    }
    while(!st.empty()){
        if(!ma[st.top()])dfs(st.top());
        st.pop();
    }
    for(i=1;i<=n;i++){
        if(!in[i])h.push({i,lvl[i]});
    }
    while(!h.empty() && t--){
        tn=h.top().n;
        tt=h.top().t;
        h.pop();
        tec[a[tn]]--;
        //printf("%d\n",tt);
        for(auto x:g[tn]){
            in[x]--;
            if(in[x]==0){
                h.push({x,lvl[x]});
            }
        }
    }
    ans=-1;
    for(i=1;i<=n;i++){
        if(tec[i]==0)ans=i;
        else break;
    }
    printf("%d\n",ans);
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
