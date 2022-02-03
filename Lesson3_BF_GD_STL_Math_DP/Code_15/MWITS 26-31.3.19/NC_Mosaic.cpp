/*
    TASK:NC_Mosaic
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000010];
queue<int> q;
int m[2010],ans[1000010];
int main()
{
    int n,k,x,y,Min=2000000000,tt,cou=1,qq,i,j;
    scanf("%d %d",&n,&k);
    while(k--)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1; i<=1000000; i++)
        sort(g[i].begin(),g[i].end());
    q.push(1);
    ans[1]=1;
    while(!q.empty())
    {
        qq=q.front();
        q.pop();
        for(auto x:g[qq]){
            if(ans[x])continue;
            for(auto y:g[x]){
                m[ans[y]]=1;
            }
            for(i=1;i<=2000;i++){
                if(m[i]!=1){
                    ans[x]=i;break;
                }
            }
            memset(m,0,sizeof m);
            q.push(x);
        }
    }
    for(i=1; i<=1000000; i++)
    {
        if(!g[i].size())continue;
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
4 4
1 999
999 9999
9999 99999
99999 1
*/
