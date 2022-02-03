/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[100010];
priority_queue< int > h;
int main()
{
    int n,a,b,d=0;
    long long sum=0,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        d=max(d,a);
    }
    while(d>0){
        if(g[d].size()>0){
            for(auto x: g[d]){
                if(x<=0) continue;
                h.push(x);
            }
        }
        if(!h.empty()){
            sum+=h.top();
            cnt++;
            h.pop();
        }
        d--;
    }
    printf("%lld\n%lld\n",sum,cnt);
    return 0;
}