/*
    TASK:NC_Dish washer
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long d,i;
    bool operator<(const A&o)const {
        return d<o.d;
    }
};
long long w[1000100],ha[1000100];
priority_queue< A > h;
int main(){
    long long l,k,i,sum=0;
    scanf("%lld %lld",&l,&k);
    for(i=1;i<=k;i++){
        scanf("%lld %lld",&w[i],&ha[i]);
        sum+=ha[i];
        if(w[i]<ha[i]){
            h.push({ha[i]-w[i],i});
        }
    }
    //printf("%d\n",sum);
    while(!h.empty() && l--){
        sum-=h.top().d;
        h.pop();
    }
    printf("%lld",sum);
}
