/*
    TASK:Electricity
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,w;
    bool operator <(const A& o) const{
    if(w!=o.w)return w>o.w;
    else return n>o.n;
    }
};
priority_queue< A > h;
int main(){
    int n,k,i,no,tn,tw,ans=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&no);
        if(h.empty()){
            h.push({i,no});
            continue;
        }
        while(!h.empty() && h.top().n<i-k)h.pop();
        h.push({i,h.top().w+no});
    }
    while(!h.empty() && h.top().n!=n)h.pop();
    printf("%d\n",h.top().w);
    return 0;
}
/*
10
4
2 1 4 3 2 1 5 1 2 3
*/
