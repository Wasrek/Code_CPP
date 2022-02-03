/*
    TASK:FC_Cocktail
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010],cnt[200010];
int main()
{
    long long n,k,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&k);
    for(int i=1;i<=n;i++){
        if(a[i]>k) continue;
        ans+=cnt[k-a[i]];
        cnt[a[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}