/*
    TASK:FC_Antler
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long cnt[2000010];
int main(){
    long long i,n,num,j,ans=0,sum;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&j);
        cnt[j]++;
    }
    for(i=1;i<=2000000;i++){
        for(j=i,sum=0;j<=2000000;j+=i)
            sum+=cnt[j];
        if(sum>=2)ans=max(ans,sum*i);
    }
    printf("%lld\n",ans);
    return 0;
}
