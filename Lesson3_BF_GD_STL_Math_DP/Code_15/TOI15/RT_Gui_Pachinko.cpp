/*
    TASK:RT_Gui Pachinko
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long> g[100010],re[100010],gg[100010];
queue< long long >q;
long long dp[100010],dgo[100010],ans[100010];
struct A
{
    long long n,dp;
    bool operator <(const A & o)const
    {
        return dp>o.dp;
    }
};
A so[100010];
priority_queue< A >h;
long long si=1,qs[100010];
void dep(long long n)
{
    for(auto x:gg[n])
    {
        dep(x);
    }
    ans[si++]=n;
}
int main()
{
    long long n,m,i,j,t,r,k,w;
    scanf("%lld %lld",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&j);
        if(j==0)
        {
            r=i;
            continue;
        }
        re[i].push_back(j);
        g[j].push_back(i);
        dgo[j]++;
    }
    for(i=1; i<=n; i++)
    {
        dp[i]=i;
        if(g[i].size()==0)
            q.push(i);
    }
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(auto x:g[t])
        {
            dp[t]=max(dp[t],dp[x]);
        }
        for(auto x:re[t])
        {
            dgo[x]--;
            if(dgo[x]==0)
                q.push(x);
        }
    }
    h.push({r,dp[r]});
    long long tn,tdp;
    while(!h.empty())
    {
        tn=h.top().n;
        h.pop();
        k=0;
        for(auto x:g[tn])
        {
            so[k].n=x;
            so[k].dp=dp[x]*-1;
            k++;
        }
        sort(so,so+k);
        for(i=0; i<k; i++)
        {
            gg[tn].push_back(so[i].n);
            h.push({so[i].n,dp[so[i].n]});
        }
    }
    dep(r);
    for(i=1; i<si; i++)
    {
        qs[i]=qs[i-1]+ans[i];
    }
    long long idx=0;
    while(m--)
    {
        scanf("%lld",&w);
        if(w==3)
        {
            printf("%lld\n",qs[idx]);
            continue;
        }
        scanf("%lld",&k);
        if(w==1)
        {
            idx+=k;printf("%lld\n",ans[idx]);
            continue;
        }
        if(w==2)
        {
            idx-=k;
        }
    }
}
