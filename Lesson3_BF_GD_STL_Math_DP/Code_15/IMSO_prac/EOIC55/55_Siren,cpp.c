/*
    TASK:55_Siren
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
vector<A> g[50010];
int main()
{
    int n,m,k,a,b,c,d,e;
    sccanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,u});
        g[b].push_back({a,u});
    }
    return 0;
}
