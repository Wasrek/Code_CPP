/*
    TASK:Toilet Manage
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> h;
map<long long,long long> mp;
int main(){
    long long q,n,k,l,r,t,m,cou,i;
    scanf("%lld",&q);
    for(i=1;i<=q;i++){
        scanf("%lld %lld",&n,&k);
        h.push(n);
        mp[n]=1;
        cou=0;
        while(!h.empty()){
            t=h.top();
            h.pop();
            m=mp[t];
            cou+=m;
            t--;
            if(t%2){
                l=t/2;
                r=t/2+1;
            }else{
            l=r=t/2;
            }
            if(cou>=k){
                printf("Case #%lld: ",i);
                printf("%lld ",max(l,r));
                printf("%lld",min(l,r));
                printf("\n");
                break;
            }
            if(mp[l]!=0){
                mp[l]+=m;
            }else{
            mp[l]=m;
            h.push(l);
            }
            if(mp[r]!=0){
                mp[r]+=m;
            }else{
            mp[r]=m;
            h.push(r);
            }
        }
        while(!h.empty())h.pop();
        mp.clear();
    }
}
