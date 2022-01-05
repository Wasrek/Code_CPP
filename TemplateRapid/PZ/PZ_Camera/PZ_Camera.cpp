/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
long long a[N],bar[N],gr[1000100],ma[N],qs[N];
int main()
{
    // freopen("3.in","r",stdin);
    long long n,q,k,l,r;
    scanf("%lld %lld %lld",&n,&q,&k);
    for(int i=1;i<=n;i++){
        if(gr[i]) continue;
        for(int j=1;j<=1000;j++){
            if(i*j*j>1000000) break;
            gr[i*j*j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]=gr[a[i]];
    }
    int now=0,cnt=0;
    for(int i=1;i<=n-k+1;i++){
        while(1){
            if(cnt>=k){
                bar[i]=now;
                qs[i]+=(qs[i-1]+bar[i]);
                break;
            }
            now++;
            if(now>n){ 
                bar[i]=2e9;
                break;
            }
            if(!ma[a[now]]) cnt++;
            ma[a[now]]++;
        }
        ma[a[i]]--;
        if(!ma[a[i]]) cnt--;
    }
    // for(int i=1;i<=n-k+1;i++){
    //     printf("%d ",bar[i]);
    // }
    int uw;
    while(q--){
        scanf("%lld %lld",&l,&r);
        uw=upper_bound(bar+1,bar+1+n-k+1,r)-bar;
        uw--;
        // printf("%d\n",uw);
        if(uw<l){
            printf("0\n");
            continue;
        }
        //l to uw approve
        //n-bar+1
        // cout << (r+1)*(uw-l+1)<<" "<<(qs[uw]-qs[l-1])<<'\n';
        printf("%lld\n",((r+1)*(uw-l+1))-(qs[uw]-qs[l-1]));
    }
    return 0;
}