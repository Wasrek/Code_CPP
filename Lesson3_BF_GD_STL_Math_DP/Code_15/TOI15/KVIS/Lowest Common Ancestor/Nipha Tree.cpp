/*
    TASK:Nipha Tree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long lvl[55];
int main(){
    long long n,k,q,a,b,maxlvl,i;
    scanf("%lld %lld %lld",&n,&k,&q);
    lvl[0]=1;
    for(i=1;i<=50;i++){
        lvl[i]=lvl[i-1]*k;
        if(lvl[i]>n){
            maxlvl=i;break;
        }
    }
    for(i=1;i<=maxlvl;i++)lvl[i]+=lvl[i-1];
    while(q--){
        long long ans=0;
        scanf("%lld %lld",&a,&b);
        if(a>b)swap(a,b);
    if(k==1){
        printf("%lld\n",b-a);continue;
    }
    long long lvla = lower_bound(lvl,lvl+maxlvl+1,a)-lvl;
    long long lvlb = lower_bound(lvl,lvl+maxlvl+1,b)-lvl;
    while(lvlb!=lvla)++ans,b=ceil((double)(b-1)/k),--lvlb;
    while(a!=b)ans+=2,a=ceil((double)(a-1)/k),b=ceil((double)(b-1)/k);
    printf("%lld\n",ans);
    }
    return 0;
}
