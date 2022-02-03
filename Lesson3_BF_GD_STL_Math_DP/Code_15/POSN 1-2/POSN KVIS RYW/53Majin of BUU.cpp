/*
    TASK:53Majin of BUU
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
//long long dsum[100100],qs[100100],a[100100];
long long mod=1000000007;
int main(){
    long long q,n,qsum,dsum,ans,num;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        qsum=dsum=ans=0;
        while(n--){
            scanf("%lld",&num);
            ans+=num*dsum;
            ans%=mod;
            qsum+=num;
            qsum%=mod;
            dsum+=qsum;
            dsum%=mod;
        }
        printf("%lld\n",ans);
    }
}
/*
    TASK:53Majin of BUU
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS

#include<bits/stdc++.h>
using namespace std;
long long dsum[100100],qs[100100],a[100100];
int main(){
    long long q,n,i,ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            qs[i]=qs[i-1]+a[i];
        }
        dsum[1]=qs[1];
        for(i=2;i<=n;i++){
            dsum[i]=dsum[i-1]+qs[i];
            ans+=(dsum[i-1]*a[i]);
            ans%=1000000007;
        }
        printf("%lld\n",ans);
    }
}
*/
