/*
    TASK:Dressing
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> h;
int in[50100],mark[50100];
vector<int> g[50100],ans;
int main()
{
    int n,m,r,s,t,ch=0,i;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&s,&r);
        in[s]++;
        g[r].push_back(s);
    }
    for(i=1; i<=n; i++){
        if(in[i]==0)
            h.push(-i);
    }
    while(!h.empty())
    {
        t=-h.top();
        ans.push_back(t);
        if(h.size()>=2) mark[ans.size()-1] = 1;
        h.pop();
        for(auto x:g[t]){
            in[x]--;
            if(in[x]==0)
                h.push(-x);
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        if(mark[i]){
            swap(ans[i],ans[i+1]);
            ch = 1;
            break;
        }
    }
    if(ans.size()!=n){
        printf("Never\n");
        return 0;
    }else if(ch == 0){
        printf("Same\n");
    }else{
        printf("Different\n");
    }
    for(auto x:ans){
        printf("%d ",x);
    }
    return 0;
}
