/*
    TASK:Up Kahn
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[100010],ans;
priority_queue< int > h;
int in[100010];
int main()
{
    int q,n,m,a,b;
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        in[b]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            h.push(-i);
        }
    }
    int now;
    while(!h.empty()){
        now=h.top();
        h.pop();
        now*=-1;
        ans.push_back(now);
        for(auto x: g[now]){
            in[x]--;
            if(in[x]==0){
                h.push(-x);
            }
        }
    }
    if(ans.size()!=n) printf("No\n");
    else {
        printf("Yes ");
        for(auto x: ans) printf("%d ",x);
        printf("\n");
    }
    for(int i=1;i<=n;i++) in[i]=0,g[i].clear();
    ans.clear();
    }
    return 0;
}