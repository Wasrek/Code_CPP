/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int bitcnt[25];
int main()
{
    int q,n;
    long long num,sum;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&num);
            for(int i=0;i<=20;i++){
                if(1ll<<i & num) bitcnt[i]++;
            }
        }
        sum=0;
        for(int i=1;i<=n;i++){
            num=0;
            for(int j=0;j<=20;j++){
                if(!bitcnt[j]) continue;
                num|=1ll<<j;
                bitcnt[j]--;
            }
            sum+=num*num;
        }
        printf("%lld\n",sum);
    }
    return 0;
}