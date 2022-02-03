#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main()
{
    long long q,n,k,p,t,mid,coun,d,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        p=0,q=1000000000;
        while(p<q)
        {
            mid=(p+q)/2;
            coun=(mid+1)*(mid+1)*n;
            for(i=1;i<n;i++)
            {
                if(a[i]==a[i-1])
                {
                    coun-=(mid+1)*(mid+1);
                    continue ;
                }
                d=a[i]-a[i-1]-1;
                if(d%2)
                {
                    d/=2;
                    if(d<mid)
                    {
                        d=mid-d;
                        coun-=(d*(d+1))/2+(d*(d-1))/2;
                    }
                }
                else
                {
                    d/=2;
                    if(d<mid)
                    {
                        d=mid-d;
                        coun-=d*(d+1);
                    }
                }
            }
            if(coun<k)
                p=mid+1;
            else
                q=mid;
        }
        printf("%lld\n",p);
    }
    return 0;
}
