/*
    TASK:FC_Codes
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1100];
int main(){
    long long n,num,ans=0,i,j;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&num);
        a[num]++;
    }
    for(i=0;i<=999;i++){
        for(j=i;j<=999;j++){
            if(i==j){
                ans+=(a[i]*(a[i]-1))/2;
                continue;
            }
            if(i%10==j%10 || i/100==j/100 || (i/10)%10==(j/10)%10)
                ans+=a[i]*a[j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
