/*
    TASK:o57_oct_c1_game
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[5010],gg[5010];
int cnt=0,cntscc=0,onstack[5010],idx[5010],lowlink[5010],sc[5010],deg[5010],in[5010];
struct A{
    int ra,idx;
};
queue< A > q;
stack < int > st;
vector< int > scc[5010];
void tarjan(int i){
    idx[i]=lowlink[i]=++cnt;
    st.push(i);
    onstack[i]=1;
    for(auto x: g[i]){
        if(idx[x]==0){//never go before
            tarjan(x);
            lowlink[i]=min(lowlink[i],lowlink[x]);
        }else if(onstack[i]){
            lowlink[i]=min(lowlink[i],idx[x]);
        }
    }
    if(idx[i]==lowlink[i]){
        while(!st.empty() && st.top()!=i){
            scc[cntscc].push_back(st.top());
            sc[st.top()]=cntscc;
            onstack[st.top()]=0;
            st.pop();
        }
        scc[cntscc].push_back(i);
        sc[i]=cntscc++;
        onstack[i]=0;
        st.pop();
    }
}
int main()
{
    int n,p,a,b;
    scanf("%d %d",&n,&p);
    for(int i=1;i<=p;i++){
        scanf("%d %d",&a,&b);
        a++;
        b++;
        g[a].push_back(b);
        in[b]=1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!in[i]){
            tarjan(i);  
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!idx[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto x: g[i]){
            if(sc[i]!=sc[x]){
                gg[sc[i]].push_back(sc[x]);
                deg[sc[x]]++;
            }
        }
    }
    for(int i=0;i<cntscc;i++){
        if(deg[i]==0){
            q.push({0,i});
        }
    }
    int ti,tr,sum=0;
    while(!q.empty()){
        ti=q.front().idx;
        tr=q.front().ra;
        q.pop();
        sum+=scc[ti].size();
        for(auto x:gg[ti]){
            deg[x]--;
            if(deg[x]==0)q.push({tr+1,x});
        }
        if(!q.empty() && q.front().ra!=tr){
            printf("%d ",sum);
            sum=0;
        }
    }

    printf("%d\n",sum);
    return 0;
}