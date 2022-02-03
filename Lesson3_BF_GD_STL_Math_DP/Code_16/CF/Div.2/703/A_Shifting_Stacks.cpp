/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,ch,a;
    long long now;
    scanf("%d",&q);
    while(q--){
        ch=0;
        now=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            now+=a;
            now-=(i-1);
            if(now<0) ch=1;
        }
        (ch) ? printf("NO\n") : printf("YES\n");
    }
    return 0;
}