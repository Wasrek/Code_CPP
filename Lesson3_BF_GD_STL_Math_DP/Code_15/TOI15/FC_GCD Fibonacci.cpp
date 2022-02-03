/*
    TASK:FC_GCD Fibonacci
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct A
{
    long long m[3][3];
};
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
long long a[3][3];
A mu[35];
A mul(A a,A b)
{
    A tmp;
    long long i,j,k;
    for(i=1; i<=2; i++)
    {
        for(j=1; j<=2; j++)
        {
            tmp.m[i][j]=0;
            for(k=1; k<=2; k++)
            {
                tmp.m[i][j]+=a.m[i][k]*b.m[k][j];
                tmp.m[i][j]%=mod;
            }
        }
    }
    return tmp;
}
A ans;
int main()
{
    long long q,n,m,g,i,j,k;
    a[1][1]=0,a[1][2]=1,a[2][1]=1,a[2][2]=1;
    scanf("%lld",&q);
    mu[0].m[1][2]=mu[0].m[2][1]=mu[0].m[2][2]=1;
    for(i=1; i<=30; i++)
    {
        mu[i]=mul(mu[i-1],mu[i-1]);
    }
    while(q--)
    {
        scanf("%lld %lld",&n,&m);
        g=gcd(n,m);
        ans.m[2][2]=1;
        ans.m[1][1]=1;
        ans.m[1][2]=ans.m[2][1]=0;
        for(i=0; i<30; i++)
        {
            if(g&(1ll<<i))
            {
                ans=mul(ans,mu[i]);
            }
        }
        printf("%lld\n",ans.m[1][2]);
    }
}
/*
2
7 10
6 12
*/
