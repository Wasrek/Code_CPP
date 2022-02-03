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
    int q,n,c;
    scanf("%d",&q);
    for(int Q=1;Q<=q;Q++){
        scanf("%d %d",&n,&c);
        if(c<n-1 || c>(n-1)*2){
            printf("Case #%d: IMPOSSIBLE\n",Q);
            continue;
        }
        printf("Case #%d:",Q);
        c-=(n-1);
        for(int i=1;i<=n-c-1;i++){
            printf(" %d",i);
        }
        for(int i=n;i>=n-c;i--){
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}