/*
    TASK:NBK48_TOI14
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    // for(int i=1;i<=n;i++) printf("%d ",a[i]);
    // printf("\n");
    for(int i=n-1;i>=1;i--){
        // printf("%lld %lld\n",a[i+1],a[i]);
        if(a[i+1]<a[i]){
            a[i]=a[i+1];
        }
    }
    // for(int i=1;i<=n;i++) printf("%lld ",a[i]);
    // printf("\n");
    long long ub;
    while(q--){
        scanf("%lld",&ub);
        ub=upper_bound(a+1,a+1+n,ub)-a;
        printf("%lld\n",ub-1);
    }
    return 0;
}