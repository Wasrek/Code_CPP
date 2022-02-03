/*
    TASK:Reya
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[110];
int main()
{
    long long q,n,m,ans,now;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s %lld",s,&m);
        if(strlen(s)<=7){
            sscanf(s,"%lld",&n);
        }else n=m-1;
        n=min(n,m-1);
        ans=1;
        now=1;
        for(int i=1;i<=n;i++){
            now*=i;
            now%=m;
            ans+=now;
            ans%=m;
        }
        printf("%lld\n",ans%m);
    }    
    return 0;
}