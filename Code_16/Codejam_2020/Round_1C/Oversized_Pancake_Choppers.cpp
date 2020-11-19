/*
    TASK:Oversized_Pancake_Choppers
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<long long ,int> mp;
int main()
{
    long long q,Q,n,d,z,o,t,ma,mi;
    long long now;
    scanf("%lld",&Q);
    for(int q=1;q<=Q;q++){
        z=o=0;
        t=1;
        ma=0;
        mi=1e18;
        scanf("%lld %lld",&n,&d);
        if(d==2)o=1;
        for(int i=1;i<=n;i++){
            scanf("%lld",&now);
            now*=2;
            ma=max(ma,now);
            mp[now]++;
            if(mp[now]==2){
                mi=min(mi,now);
            }
            if(mp[now]>=d){
                z=1;
            }else if((mp[now/2])>=1 || mp[now*2]>=1){
                o=1;
            }
        }
        printf("Case #%d: ",q);
        if(ma>mi) o=1;
        if(z){
            printf("0\n");
        }else if(o==1 || d==2){
            printf("1\n");
        }else printf("2\n");
        mp.clear();
    }
    return 0;
}