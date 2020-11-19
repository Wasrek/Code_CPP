/*
    TASK: Permu Order
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010],h;
long fac(long number)
{
    if(number<=1)
        return 1;
    else
        return(number*fac(number-1))%h;
}
int main()
{
    long long n,q,i,k,sum=0,ne,j,c;
    scanf("%lld %lld",&n,&q);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    //printf("%d",sum);
    while(q--)
    {
        scanf("%lld",&h);
        for(i=1; i<=n; i++)
        {
            c=1;
            for(j=1; j<i; j++)
            {
                if(a[j]<a[i])
                    c++;
            }
            //printf(" =%d ",c);
            k=a[i]-c;//printf(" =%d ",k);
            sum+=(k*fac(n-i));
        }
        sum+=1;
        printf("%lld\n",sum%h);
        sum=0;
    }
}

