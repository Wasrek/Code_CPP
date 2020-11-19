/*
    TASK:Divisibility Problem
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,a,b;
    long long d;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        d=(long long)(ceil((double)a/(double)b))*b;
        printf("%lld\n",d-a);
    }
    return 0;
}