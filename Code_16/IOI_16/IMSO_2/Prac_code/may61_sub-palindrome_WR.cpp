#include<bits/stdc++.h>
using namespace std;
long long P=1000000007,qspow[100010],qs[100010],qs2[100010],dp[100010],dp2[100010];
char a[100010];
int main(){
    long long i,j,n,l,r,q,sum=0,mid,pl,pr;
    scanf("%lld",&n);
    scanf(" %s",a+1);
    qspow[0]=1;
    for(i=1;i<=n;i++){
        qspow[i]=qspow[i-1]*P;
    }
    for(i=1;i<=n;i++){
        qs[i]=qs[i-1]+(a[i]-'a')*qspow[i];
    }
    for(i=n;i>=1;i--){
        qs2[i]=qs2[i+1]+(a[i]-'a')*qspow[n-i+1];
    }
    for(i=1;i<=n;i++){
        l=0;
        r=min(i,n-i+1);
        while(l<r){
            mid=(l+r+1)/2;
            pl=(qs[i]-qs[i-mid])*qspow[n-i+1];
            pr=(qs2[i]-qs2[i+mid])*qspow[i];
            if(pl==pr) l=mid;
            else r=mid-1;
        }
        dp[i]=l;
    }
    for(i=1;i<n;i++){
        if(a[i]!=a[i+1]) continue;
        l=0;
        r=min(i,n-i);
        while(l<r){
            mid=(l+r+1)/2;
            pl=(qs[i]-qs[i-mid])*qspow[n-i];
            pr=(qs2[i+1]-qs2[i+mid+1])*qspow[i];
            if(pl==pr) l=mid;
            else r=mid-1;
        }
        dp2[i]=l;
    }

return 0;
}
