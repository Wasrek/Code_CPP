/*
    TASK:A - Digital root
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long q,x,k;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&x,&k);
        printf("%lld\n",k+(9*(x-1)));
    }
    return 0;
}
