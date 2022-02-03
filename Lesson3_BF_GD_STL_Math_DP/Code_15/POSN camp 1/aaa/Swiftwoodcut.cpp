/*
    TASK:Swift Wood Cut
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long d[1000010];
int main()
{
    long long a,b,i,l,r,mid,sum;
    scanf("%lld %lld",&a,&b);
    for(i=0;i<a;i++)
        scanf("%lld",&d[i]);
    l=0,r=200000000000000000;
    while(l<r){
        mid=(l+r+1)/2;
        for(i=0,sum=0;i<a;i++){
            if(mid<d[i])
                sum+=d[i]-mid;
        }
        if(sum>=b) l=mid;
        else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}

















\
\








































































































































































