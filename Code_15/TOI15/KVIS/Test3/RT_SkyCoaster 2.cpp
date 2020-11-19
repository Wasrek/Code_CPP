/*
    TASK:RT_SkyCoaster 2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010],a[200010],b[200010];
int main(){
    long long q,i,j,n,c,st,ch,force,cnt,want;
    scanf("%lld",&q);
    while(q--){
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        scanf("%lld %lld",&n,&c);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
            a[i+n]=a[i];
        }
        for(i=0;i<n;i++){
            scanf("%lld",&b[i]);
            b[i+n]=b[i];
        }
        st=0,ch=0,force=0;
        for(i=0;i<2*n;i++){
            force=min(c,a[i]+force)-b[i];//force from previous
            if(force<0)st=i+1,force=0;//restart from i+1
            if(i-st==n-1){
                ch=1;break;
            }
        }
        if(!ch){
            printf("0\n");
            continue;
        }
        cnt=1;
        for(i=(st-1+n)%n;i!=st;i=(i-1+n)%n){
            want = max(0ll,b[i]-min(c,a[i]));
            dp[i]=max(want,dp[(i+1)%n]-(min(c,a[i])-b[i]));
            if(min(a[i],c)-b[i]>=dp[(i+1)%n])cnt++;
        }
        printf("%lld\n",cnt);
    }
}
