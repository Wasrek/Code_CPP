/*
    TASK:Water Buying
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
//long long dp[1000000000100];
int main()
{
    long long q,n,a,b,Min;
    scanf("%I64d",&q);
    while(q--)
    {
        scanf("%I64d %I64d %I64d",&n,&a,&b);
        if((a*2)<=b)
        {
            printf("%I64d\n",n*a);
        }
        else
        {
            if(n%2==0)
            {
                printf("%I64d\n",n/2*b);
            }
            else
            {
                Min=min((n-1)*b/2+a,(n*a));
                printf("%I64d\n",Min);
            }
        }
    }
    return 0;
}
