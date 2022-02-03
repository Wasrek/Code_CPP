/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000010
#define iden 10
long long pre[SIZE],pos[SIZE],power[SIZE],dp[SIZE];
char a[SIZE];
int main()
{
    int n;
    scanf("%d",&n);
    scanf(" %s",a+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='A') a[i]=1;
        else if(a[i]=='C') a[i]=2;
        else if(a[i]=='T') a[i]=3;
        else if(a[i]=='G') a[i]=4;
    }
    power[0]=1;
    for(int i=1;i<=n;i++){
        pre[i]=(pre[i-1]*iden)+a[i];
        power[i]=power[i-1]*iden;
    }
    for(int i=n;i>0;i--){
        pos[i]=(pos[i+1]*iden)+a[i];
    }
    int l,r,mid,pl,pr;
    for(int i=1;i<=n;i++){
        // printf("%d\n",i);
        l=0,r=min(i-1,n-i);
        while(l<r){
            mid=(l+r+1)>>1;
            pl=pre[i]-(pre[i-mid-1]*power[mid+1]);
            pr=pos[i]-(pos[i+mid+1]*power[mid+1]);
            // printf("%d %lld %lld\n",mid,pl,pr);
            if(pl==pr) l=mid;
            else r=mid-1;
        }
        dp[l*2+1]++;
        // printf("%d ",l);
        l=0,r=min(i,n-i);
        while(l<r){
            mid=(l+r+1)>>1;
            pl=pre[i]-(pre[i-mid]*power[mid]);
            pr=pos[i+1]-(pos[i+1+mid]*power[mid]);
            if(pl==pr) l=mid;
            else r=mid-1;
        }
        dp[l*2]++;
        // printf("%d\n",l);
    }
    for(int i=n;i>=1;i--){
        dp[i]+=dp[i+2];
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",dp[i]);
    }
    return 0;
}