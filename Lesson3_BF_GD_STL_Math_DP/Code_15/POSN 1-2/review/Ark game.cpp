/*
    TASK:Ark game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
int main(){
    long long i,n,k,l,r,cnt;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    l=1,r=2000000000;
    long long now,mid;
    while(l<r){
        mid=(l+r+1)/2;
        cnt=1;
        now=a[1]+mid;
        for(i=2;i<=n;i++){
            if(now<=a[i]){
                cnt++;
                now=a[i]+mid;
            }
        }
        if(cnt>=k){
            l=mid;
        }else{
        r=mid-1;
        }
    }
    printf("%lld\n",r);
}
