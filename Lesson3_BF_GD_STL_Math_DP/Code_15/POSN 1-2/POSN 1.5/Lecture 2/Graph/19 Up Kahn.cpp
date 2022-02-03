/*
    TASK:Up Kahn
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> he;
int in[100100];
vector<int> g[100100],ans;
int main()
{
    int q,n,m,i,r,s,u;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&r,&s);
            in[s]++;
            g[r].push_back(s);
        }
        for(i=1;i<=n;i++)
            if(in[i]==0)
            he.push(-i);
        while(!he.empty()){
            u=he.top()*-1;he.pop();
            ans.push_back(u);
            for(auto x: g[u]){
                in[x]--;
                if(in[x]==0)
                    he.push(-x);
            }
        }
        if(ans.size()==n){
            printf("Yes");
            for(i=0;i<n;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
        else
            printf("No\n");
        memset(in,0,sizeof in);
        ans.clear();
        for(i=1;i<=n;i++)
            g[i].clear();

    }
    return 0;
}
