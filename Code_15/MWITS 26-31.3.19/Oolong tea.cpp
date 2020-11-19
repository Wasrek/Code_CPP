/*
    TASK:Oolong tea
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long cost,type,idx;
    bool operator <(const A&o) const{
        if(cost!=o.cost)return cost>o.cost;
        return type>o.type;
    }
};
priority_queue< A > h;
long long mark[50005];
int main(){
    long long n,m,k,i,c,d,ans=0;
    scanf("%lld %lld %lld",&n,&k,&m);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&c,&d);
        h.push({c,0,i});h.push({d,1,i});

    }
    while(!h.empty()){
        c=h.top().cost,d=h.top().type,i=h.top().idx;
        h.pop();
        if(!mark[i] && c<=m && d<=k){
            ans++;mark[i]=1;m-=c;k-=d;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
