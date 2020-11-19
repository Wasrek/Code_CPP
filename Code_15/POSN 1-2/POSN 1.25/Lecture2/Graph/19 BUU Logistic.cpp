/*
    TASK:BUU Logistic
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> a;
struct A
{
    int nn,dis;
};
vector< int > c[500];
queue< A > q;
int mark[35];
int main()
{
    char na[3],nf[3],nt[3];
    int i,nu=1,m,n,p,g,tf,tt,now,d,j;
    long long ans;
    scanf("%d %d %d",&m,&n,&p);
    for(i=0; i<m; i++)
    {
        scanf(" %s",na);
        a[na]=nu;
        nu++;
    }
    for(i=0; i<n; i++)
    {
        scanf(" %s %s",nf,nt);
        c[a[nf]].push_back(a[nt]);
        c[a[nt]].push_back(a[nf]);
    }
    for(i=0; i<p; i++)
    {
        scanf("%d %s %s",&g,nf,nt);
        tf=a[nf];
        tt=a[nt];
        ans = 1e9;
        q.push({tf,0});
        mark[tf] = 1;
        while(!q.empty())
        {
            now=q.front() .nn;
            d=q.front() .dis;
            q.pop();
            for(j=0; j<c[now].size(); j++)
            {
                if(mark[c[now][j]]!=1)
                {
                    mark[c[now][j]] = 1;
                    if(c[now][j]==tt)
                    {
                        d++;
                        ans=d*g*1128;
                        break;
                    }
                    else
                        q.push({c[now][j],d+1});
                }
            }
        }
        if(ans!=1e9)
            printf("%s %s %d\n",nf,nt,ans);
        else
            printf("NO SHIPMENT POSSIBLE\n");
        while(!q.empty())   q.pop();
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
6 7 4
AA CC QR FF DD AB
AA CC
CC QR
DD CC
AA DD
AA AB
DD QR
AB DD
*/
