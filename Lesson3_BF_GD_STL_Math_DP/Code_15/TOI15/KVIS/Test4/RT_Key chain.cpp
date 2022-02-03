/*
    TASK:RT_Key chain
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[100010];
map<long long , long long > mp;
int main()
{
    long long n,k,i,ans,loop = 0;
    scanf("%lld %lld", &n, &k);
    for (i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        mp[a[i]] = i;
    }
    for(i=1;i<n;i++){
        b[i] = (mp[i+1]-mp[i]+n)%n;
        loop+=b[i];
    }
    b[n] = (mp[1]-mp[n]+n)%n;
    loop+=b[n];
    k--;
    ans = loop*(k/n);
    k%=n;
    for(i=1;i<=k;i++)
        ans+=b[i];
    printf("%lld\n", ans+mp[1]-1);
    return 0;
}
/*
4 6
4
2
1
3
*/
