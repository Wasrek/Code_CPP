/*
    TASK:Maximum Subsequence Sum
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sum=0,ma=-1e9,l,r,m,now,ansi,ansj;
    l=r=1;
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld",&now);
        sum+=now;
        if(ma<sum){
            ma=sum;
            r=i;
            ansi=l;
            ansj=r;
        }
        if(sum<0){
            r=l=i+1;
            sum=0;
        }
        // printf("%lld\n",sum);
    }
    // printf("%lld %lld\n%lld\n",l,r,ma);
    // printf("%lld %lld\n%lld\n",ll,rr,maa);
    printf("%lld %lld\n%lld\n",ansi,ansj,ma);
    return 0;
}