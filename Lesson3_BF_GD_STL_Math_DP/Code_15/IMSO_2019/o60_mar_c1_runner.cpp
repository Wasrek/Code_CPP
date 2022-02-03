/*
    TASK:runner
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include <bits/stdc++.h>
using namespace std;
long long t[2100], v[2100];
int main()
{
    long long n, m,p,e,s,ans;
    scanf("%lld %lld", &n, &m);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &t[i], &v[i]);
    }
    for (long long j = 1; j <= m; j++)
    {
        scanf("%lld %lld %lld", &p, &s, &e);
        long long ch = 0, now,ans=0;
        for (long long i = 1; i <= n; i++)
        {
            if (p % v[i])
                ch = 1;
            else
                ch = 0;
            now = t[i]*v[i] + p;
            // printf("%d %d %d\n",i,j,now);
            if (s*v[i] <= now && now <= e*v[i])
            {
                ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}