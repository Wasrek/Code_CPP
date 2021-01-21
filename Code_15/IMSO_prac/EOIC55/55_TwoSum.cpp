/*
    TASK:55_TwoSum
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int c[2000000],a[500010];
int main()
{
    int q,n,i,j;
    long long ans;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]+=a[i-1];
            if(a[i]==0)ans++;
            if(c[a[i]+1000000]>0)ans+=c[a[i]+1000000];
            c[a[i]+1000000]++;
        }
        printf("%lld\n",ans);
        memset(c,0,sizeof c);
    }
    return 0;
}
