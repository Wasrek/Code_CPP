/*
    TASK:
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long q,i,now,d;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&i);
        i%=1000000007;
        now=i+1;
        now%=1000000007;
        if(i%2==0)
        now*=(i/2%1000000007);
        else d=now/2%1000000007,now*=(i/2%1000000007),now+=d;
        now%=1000000007;
        printf("%lld\n",now);
    }
}
