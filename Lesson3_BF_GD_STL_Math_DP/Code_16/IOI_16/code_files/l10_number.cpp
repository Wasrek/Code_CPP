/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[15],ans[15];
int main()
{
    long long n,mi=1<<30,lak,now;
    scanf("%lld",&n);
    for(int i=1;i<=9;i++){
        scanf("%lld",&a[i]);
        if(a[i]<=mi){
            mi=a[i];
            now=i;
        }
    }
    lak=n/mi;
    n-=(mi*lak);
    ans[now]=lak;
    for(int j=9;j>now;j--){
        if(a[j]-mi<=n){
            ans[j]=min(ans[now],n/(a[j]-mi));
            n-=(ans[j]*(a[j]-mi));
            ans[now]-=ans[j];
        }
        if(ans[now]==0) break;
    }
    for(int i=9;i>=now;i--){
        if(ans[i]<=0) continue;
        for(int j=1;j<=ans[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}