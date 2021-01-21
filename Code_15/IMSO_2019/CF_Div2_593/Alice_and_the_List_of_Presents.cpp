/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long a[33],b[33];
int main()
{
    int n,m,ans=1;
    scanf("%d %d",&n,&m);
    a[0]=2;
    for(int i=1;i<=31;i++){
        a[i]=(a[i-1]*a[i-1])%mod;
    }
    for(int i=0;i<=31;i++){
        if((1<<i) & m){
            ans*=(a[i]%mod);
            ans%=mod;
        }
    }
    ans--;
    b[0]=ans;
    for(int i=1;i<=31;i++){
        b[i]=(b[i-1]*b[i-1])%mod;
    }
    ans=1;
    for(int i=0;i<=31;i++){
        if((1<<i) & n){
            ans*=(b[i]%mod);
            ans%=mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}
