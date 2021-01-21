/*
    TASK:C-Minimum_Integer
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d",&q);
    long long l,r,d;
    while(q--){
        scanf("%lld %lld %lld",&l,&r,&d);
        if(d<l){
            printf("%lld\n",d);
            continue;
        }
        else
        printf("%lld\n",d*(r/d+1));
    }
    return 0;
}
