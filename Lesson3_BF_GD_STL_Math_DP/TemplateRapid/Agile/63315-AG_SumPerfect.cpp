#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> p;
int main(){
    int q,n,i;
    long long a,x,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a);
            p.push(-a);
        }
        v=0;
        while(!p.empty()){
            x=p.top();
            p.pop();
            if(!p.empty() && x==p.top()){
                p.pop();
                p.push(x-1);
            }
            else v++;
        }
        printf("%lld\n",-x-v+1);
    }
    return 0;
}
