/*
    TASK:Mod of power
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long mop(long long a,long long b,long long c){
    if(b==1) return a%c;
    long long n=mop(a,b/2,c);
    if(b%2==0){
        return (n*n)%c;
    }else return (n*n*a)%c;
}
int main()
{
    int q;
    int a,b,c;
    long long ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        ans=mop(a,b,c);
        printf("%lld\n",ans);
    }
    return 0;
}