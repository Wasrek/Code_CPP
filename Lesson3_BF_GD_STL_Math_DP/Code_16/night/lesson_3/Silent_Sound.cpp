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
vector< long long > ans;
int main()
{
    long long n,m,c,v,now=0;
    scanf("%lld %lld %lld",&n,&m,&c);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v);
        while(!dqma.empty() && dqma.front().i+m-1<i) dqma.pop_front();
        while(!dqmi.empty() && dqmi.front().i+m-1<i) dqmi.pop_front();
        while(!dqma.empty() && dqma.back().v<v) dqma.pop_back();
        while(!dqmi.empty() && dqmi.back().v>v) dqmi.pop_back();
        dqma.push_back({i,v});
        dqmi.push_back({i,v});
        now=dqma.front().v-dqmi.front().v;
        if(now<=c && i>=m){
            ans.push_back({i-m+1});
        }
    }
    if(!ans.size()){ printf("NONE\n");return 0;}
    for(auto x: ans) printf("%lld\n",x);
    return 0;
}