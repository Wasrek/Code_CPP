/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,v;
};
deque< A > dqma,dqmi;
long long v[1000010];
int main()
{
    long long n,a,b,now=0,ans=0;
    scanf("%lld %lld %lld",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        while(!dqma.empty() && dqma.back().v<v[i]) dqma.pop_back();
        while(!dqmi.empty() && dqmi.back().v>v[i]) dqmi.pop_back();
        dqma.push_back({i,v[i]});
        dqmi.push_back({i,v[i]});
        while(!dqma.empty() && !dqmi.empty() && dqma.front().v-dqmi.front().v>b){
            if(dqmi.front().i<dqma.front().i){now=dqmi.front().i;dqmi.pop_front();}
            else{now=dqma.front().i;dqma.pop_front();}
        }
        ans+=(i-now);
    }
    while(!dqmi.empty()) dqmi.pop_back();
    while(!dqma.empty()) dqma.pop_back();
    now=0;
    for(int i=1;i<=n;i++){
        while(!dqma.empty() && dqma.back().v<v[i]) dqma.pop_back();
        while(!dqmi.empty() && dqmi.back().v>v[i]) dqmi.pop_back();
        dqma.push_back({i,v[i]});
        dqmi.push_back({i,v[i]});
        while(!dqma.empty() && !dqmi.empty() && dqma.front().v-dqmi.front().v>=a){
            if(dqmi.front().i<dqma.front().i){now=dqmi.front().i;dqmi.pop_front();}
            else{now=dqma.front().i;dqma.pop_front();}
        }
        ans-=(i-now);
    }
    printf("%lld\n",ans);
    return 0;
}