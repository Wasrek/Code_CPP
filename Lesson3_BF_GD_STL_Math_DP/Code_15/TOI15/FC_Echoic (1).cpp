#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long mic[10005][2];
long long a[100005];
int main()
{
    long long n,i,j,nw,la;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(a[1]!=0 && a[1]!=-1)
    {
        printf("0");
        return 0;
    }
    a[1]=a[n]=0;
    mic[0][0]=1;
    for(i=1;i<=n;i++)
    {
        nw=i&1;
        la=(i+1)&1;
        if(a[i]!=-1)
        {
            for(j=0;j<=10000;j++)
                mic[j][nw]=0;
            mic[a[i]][nw]=mic[a[i]][la]+mic[a[i]+1][la];

            if(a[i]>0)
                mic[a[i]][nw]+=mic[a[i]-1][la];
            mic[a[i]][nw]%=mod;

        }
        else
        {
            mic[0][nw]=(mic[0][la]+mic[1][la])%mod;
            //printf("%lld ",mic[0][nw]);
            for(j=1;j<=10000;j++)
            {
                mic[j][nw]=(mic[j-1][la]+mic[j][la]+mic[j+1][la])%mod;
                //printf("%lld ",mic[j][nw]);
            }
        }
        //printf("\n");
    }
    printf("%lld",mic[0][n&1]);
    return 0;
}
