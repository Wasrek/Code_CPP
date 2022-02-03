/*
    TASK: Q_Far far away
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int t,w;
};
vector<A> o[100050];
queue< A> q;
int mark[100050];
int main()
{
    int p,c,m,i,e,l,t,w,ma,Max=-1;
    scanf("%d",&p);
    while(p--)
    {
        int f;
        scanf("%d %d",&c,&m);
        for(i=0;i<c-1;i++){
            scanf("%d %d %d",&f,&e,&l);
            o[f].push_back({e,l});
        }
        memset(mark,0,sizeof mark);
        q.push({1,0});
        while(!q.empty())
        {
            t=q.front().t,w=q.front().w;
            q.pop();
            Max = max(Max,w);
            for(i=0;i<o[t].size();i++)
            {
                if(mark[o[t][i].t]) continue;
                mark[o[t][i].t] = 1;
                q.push({o[t][i].t,w+o[t][i].w});
            }
        }
        if(Max>=m)
            printf("%d\n",Max);
        else
            printf("-1\n");
        Max=-1;
        for(i=1;i<=c;i++)
            o[i].clear();
    }
}
