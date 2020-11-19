/*
    TASK:RC_Peatlindrome
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010],f[1000010],b[1000010],bb[1000010];
int main(){
    long long q,n,i,l,r,s,e,ans,lb;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=1;i<=n;i++){
            f[i]=f[i-1]+a[i];
//            printf("%lld ",f[i]);
        }
//        printf("\n");
        b[n+1]=0;
        for(i=n;i>=1;i--){
            b[i]=b[i+1]+a[i];
            bb[n-i+1]=b[i];
        }
//        for(i=1;i<=n;i++)printf("%lld ",b[i]);
//        printf("\n");
        s=1;
        e=n;
        ans=0;
        while(1){
            if(s>=e)break;
            if(f[s]==b[e]){s++,e--;continue;}//printf("- %lld %lld %lld %lld -",f[s],b[e],s,e);
            while(f[s]!=b[e] && s<e){
//                printf("%lld %lld\n",s,e);
                if(f[s]>b[e]){
                    lb=lower_bound(bb+1,bb+1+n,f[s])-bb;
                    lb=n-lb+1;
//                    printf("lb %lld\n",lb);
                    ans+=(e-lb);
                    e=lb;
                }else{
                    lb=lower_bound(f+1,f+1+n,b[e])-f;
                    ans+=(lb-s);
//                    printf("lb %lld\n",lb);
                    s=lb;
                }
//                printf("%lld\n",ans);
            }
        }
        printf("%lld\n",ans);
    }
}
