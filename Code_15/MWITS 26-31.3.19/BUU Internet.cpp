/*
    TASK:BUU Internet
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long u[120];
int main(){
    long long n,m,i,l,r,mid,cou,last,Max=0;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&u[i]);
        Max=max(Max,u[i]);
    }
    l=Max;r=2000000000;
    while(l<r){
        mid=(l+r)/2;
        cou=1,last=0;
        for(i=1;i<=n;i++){
            if(u[i]+last>mid){
                cou++,last=u[i];
            }else{
            last+=u[i];
            }
        }
        //if(last!=0)cou++;
        if(cou<=m)r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
}
