/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp;
int main()
{
    long long n,m,now=0,ans=0;
    char s;
    mp[0]=1;
    scanf("%lld %lld",&n,&m);
    for(int i=2;i<=n+1;i++){
        scanf(" %c",&s);
        if(s=='R'){
            now-=m;
        }else{ 
            now++;
        }
        if(mp[now]) ans=max(ans,i-mp[now]);
        if(!mp[now])mp[now]=i;
        // printf("%d\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}