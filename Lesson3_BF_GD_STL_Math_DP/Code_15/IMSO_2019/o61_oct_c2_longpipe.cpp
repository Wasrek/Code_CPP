/*
    TASK:Long Pipe
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct A
{
    long long a[5][5];
};
A dp[32];
A c;
void mul(A *a,A *b)
{
    int i,j,k;
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++)
        {
            c.a[i][j]=0;
            for(k=1; k<=3; k++)
            {
                c.a[i][j]+=(a->a[i][k]%mod*b->a[k][j]%mod)%mod;
                c.a[i][j]%=mod;
            }
        }
    }
}
A tmp;
A ans;
int main()
{
    int i,j;
    long long answer;
    dp[0]= {{{},{0,1,1,1},{0,2,1,0},{0,1,0,1}}};
    int n;
    scanf("%d",&n);
    n++;
    for(i=1; i<=30; i++)
    {
        mul(&dp[i-1],&dp[i-1]);
        dp[i]=c;
    }
    for(i=1; i<=3; i++)
        tmp.a[i][i]=1;
    for(i=0; i<=30; i++)
    {
        if(n&(1<<i))
        {
            mul(&tmp,&dp[i]);
            tmp=c;
        }
    }
    // ans.a[1][1]=ans.a[2][1]=1;
    // ans.a[3][1]=0;
    // mul(&ans,&tmp);
    // ans=c;
    // answer=((ans.a[1][1]*2)+(ans.a[2][1]))%mod;
    answer = tmp.a[2][1] + tmp.a[2][2];
    answer %= mod;
    printf("%lld",answer);
    return 0;
}