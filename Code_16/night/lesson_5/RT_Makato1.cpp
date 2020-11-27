/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
    int n,q,l,r;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]^=a[i-1];
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        printf("%lld\n",a[r]^a[l-1]);
    }
    return 0;
}
/*
5 5
2 6 2 9 1
5 5
1 5
2 3
4 5
2 4
*/