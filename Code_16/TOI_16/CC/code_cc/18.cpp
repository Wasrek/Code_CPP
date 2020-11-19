/*
    TASK:MaxMin
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int now,ma=0,mi=2e9;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&now);
        ma=max(ma,now);
        mi=min(mi,now);
    }
    printf("%d\n%d",ma,mi);
    return 0;
}