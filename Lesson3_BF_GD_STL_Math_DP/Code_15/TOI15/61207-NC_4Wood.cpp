/*
    TASK:FC_Antler
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long fac[100010];
int main(){
    long long q,n,m,f,i,j,ans,now,k;
    scanf("%lld",&q);
    fac[1]=fac[0]=1;
    for(i=2;i<=100000;i++){
        fac[i]=i*fac[i-1];
        //fac[i]%=100003;
    }
    while(q--){
        scanf("%lld",&n);
        if(n<4){
            printf("1\n");
            continue;
        }
        f=n/4;
        ans=1;
        k=j=n;
        i=0;
        while((k-3)>0 && (j-4)>=0){
            k-=3;
            j-=4;
            i++;
            now=fac[k]/(fac[i]*fac[j]);
            //printf("%lld %lld %lld %lld\n",fac[k],fac[i],fac[j],now);
            ans+=now;
            ans%=100003;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
