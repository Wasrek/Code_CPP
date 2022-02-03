#include<bits/stdc++.h>
using namespace std;
long long r[35],pass=0;
long long play(long long state,long long m)
{
    long long num=(2*m)+1-r[state];
    if(num<2){
        pass=1; return -1;
    }
    if(state==1)    return num;
    long long value1=play(state-1,num/2),value2=play(state-1,(num/2)+1);
    if(num%2==1)  return value1+value2;
    else            return 2*value1;
}
int main()
{
    long long q,n,m;
    scanf("%lld",&q);
    while(q--){
        pass=0;
        scanf("%lld %lld",&n,&m);
        for(long long i=1;i<n;i++)
            scanf("%lld",&r[i]);
        long long res=play(n-1,m);
        if(res<=0 || pass==1) printf("-1\n");
        else                 printf("%lld\n",res);
    }
    return 0;
}
