/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< long long > x,y;
int main()
{
    long long q,n,a,b;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&a,&b);
            x.push_back(a);
            y.push_back(b);
        }
        if(x.size()%2==0) sort(x.begin(),x.end());
        if(y.size()%2==0) sort(y.begin(),y.end());
        if(x.size()%2==0) a=x[x.size()/2]-x[x.size()/2-1]+1;
        else a=1;
        if(y.size()%2==0) b=y[y.size()/2]-y[y.size()/2-1]+1;
        else b=1;
        printf("%lld\n",a*b);
        x.clear();y.clear();
    }
    return 0;
}