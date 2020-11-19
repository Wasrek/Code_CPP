/*
    TASK:BUU Contest
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> a;
int main()
{
    long long d,k,n,b,sum=0,ans=0,num;
    scanf("%lld %lld",&d,&k);
    while(d--){
        scanf("%lld %lld",&n,&b);
        while(n--){
            scanf("%lld",&num);
            a.push(num-sum);
        }
        while(b--){
            ans+=a.top()+sum;
            a.pop();
        }
        sum+=k;
    }
    printf("%lld\n",ans);
}
