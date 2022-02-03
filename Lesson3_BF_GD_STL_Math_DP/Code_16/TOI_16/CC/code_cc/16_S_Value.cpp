/*
    TASK:S-Value
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2100];
int main()
{
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n*2;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+(n*2));
    long long sum=0;
    long long l=1,r=n*2;
    while(l<=n){
        sum+=a[l]*a[r];
        l++;
        r--;
    }
    printf("%lld\n",sum);
    return 0;
}