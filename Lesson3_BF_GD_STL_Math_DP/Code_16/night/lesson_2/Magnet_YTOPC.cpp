/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,v;
    bool operator<(const A & o) const{
        return i<o.i;
    }
};
A event[200100];
vector< int > g;
int main()
{
    int n,m,q,a,b,ub,last=-1;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        event[i*2+1]={a,1};
        event[i*2+2]={a+b,-1};
    }
    sort(event+1,event+1+2*m);
    event[2*m+1].i=n+1;
    g.push_back(1);
    for(int i=1;i<=2*m;i++){
        event[i].v+=event[i-1].v;
        // printf("%d %d %d\n",event[i].v,event[i].i,last);
        if(event[i].i==event[i+1].i) continue;
        if(event[i].v%2==last) continue;
        g.push_back(event[i].i);
        last=event[i].v%2;
    }
    g.push_back(n+1);
    // for(auto x: g) printf("%d ",x);
    // printf("\n");
    for(int i=1;i<=q;i++){
        scanf("%d",&a);
        ub=upper_bound(g.begin(),g.end(),a)-g.begin();
        printf("%d\n",g[ub]-g[ub-1]);
    }
    return 0;
}