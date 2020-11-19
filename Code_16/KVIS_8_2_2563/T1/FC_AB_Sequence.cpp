/*
    TASK:FC_AB Sequence
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110];
int main()
{
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]*=i;
    }
    printf("%lld ",a[1]);
    for(int i=2;i<=n;i++){
        printf("%lld ",a[i]-a[i-1]);
    }
    return 0;
}