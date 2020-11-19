/*
    TASK:blowblock
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< int > h;
vector< int > a[7];;
int main()
{
    int n,now,g;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&now);
            g=((i%2)*2)+(j%2);
            a[g].push_back(now);
        }
    }
    for(int i=0;i<4;i++){
        sort(a[i].begin(),a[i].end());
    }
    for(int i=0;i<(n*n/4);i++){
        ans+=(a[0][i]*a[1][i]*a[2][i]*a[3][i]);
    }
    printf("%lld\n",ans);
    return 0;
}