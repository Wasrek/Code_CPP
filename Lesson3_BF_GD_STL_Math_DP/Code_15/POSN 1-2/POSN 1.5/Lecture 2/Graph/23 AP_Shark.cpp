/*
    TASK:AP_Shark
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int n,w;
};
vector< int > c[1010];
queue< A > q;
int w[1010],mark[1010],ch[1010];
int main()
{
    int i,n,m,x,y,Max=0,now,dis,wei,d,j,ans;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&w[i]);
        if(w[i]>Max)
            Max=w[i],ans=i;
    }
    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&x,&y);
        c[x].push_back(y);
        mark[y]=2;
    }
    for(i=1;i<=n;i++){
        if(mark[i]!=2){
        q.push({i,w[i]});
        wei=0;
        while(!q.empty())
        {
            now=q.front() .n;
            d=q.front() .w;
            q.pop();
            for(j=0; j<c[now].size(); j++)
            {
                if(ch[c[now][j]]!=i){
                ch[c[now][j]]=i;
                wei=d+w[c[now][j]];
                q.push({c[now][j],wei});
                }
            }
        }
        if(wei>=Max)
                {
                    if(wei==Max)
                    {
                        if(c[now][j]<ans)
                            ans=i;
                    }
                    else
                        ans=i;
                    Max=wei;
                }
        }
    }
    printf("%d %d\n",ans,Max);
}
/*
5 6
7 2 3 9 4
1 3
2 5
4 1
3 5
4 5
2 1
*/
/*
5 5
4 2 6 3 5
4 1
3 1
4 3
5 2
5 3
*/
