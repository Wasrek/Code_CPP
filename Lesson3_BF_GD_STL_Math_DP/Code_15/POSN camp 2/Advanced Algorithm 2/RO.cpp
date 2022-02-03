/*
    TASK:RO
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
map<long long,int> mp;
char a[1000010];
int main(){
    long long n,k,qs=0,ans=0,i;
    scanf("%lld %lld %s",&n,&k,a+1);
    for(i=1;i<=n;i++){
        if(a[i]=='O')qs++;
        else if(a[i]=='R')qs-=k;
        if(mp[qs])ans=max(ans,i-mp[qs]);
        else mp[qs]=i;
    }
    printf("%lld\n",ans);
    return 0;
}
