/*
    TASK:55_TwoThree
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,d,a,b,ans=0,c;
    scanf("%d %d",&q,&d);
    while(q--){
        scanf("%d %d",&a,&b);
        if(a<b)swap(a,b);
        if(a-b<=d)ans+=a;
        if(a-b>d){
            scanf("%d",&c);
            ans+=c;
        }
    }
    printf("%d",ans);
    return 0;
}
