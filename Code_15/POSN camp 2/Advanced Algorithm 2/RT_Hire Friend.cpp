/*
    TASK:RT_Hire Friend
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp;
int main(){
    long long n,s,e,i,ans=0,last=0,qs=0;;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld %lld",&s,&e);
        mp[s]++,mp[e+1]--;
    }
    for(auto p:mp){
        if(qs>1){
            ans+=(qs-1)*(p.first-last);
        }
        qs+=p.second;
        last=p.first;
    }
    printf("%lld\n",ans);
    return 0;
}
