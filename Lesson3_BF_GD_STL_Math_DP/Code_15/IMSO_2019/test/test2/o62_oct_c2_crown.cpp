/*
    TASK:o62_oct_c2_crown
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],dp[200100],re[200100],b[200100],mar[200100],mab[200100];
int main()
{
    int n,ans=0,mi=1e9,di=0,ze=0,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i>=3){
            if(a[i-2]>1 && a[i-1]>0 && a[i]>1)cnt=1;
        }
        b[n-(i-1)]=a[i];
        if(a[i]==0){
            dp[i]=0;
            ze=i;
            mi=1e9;
            continue;
        }
        if(a[i]>a[i-1] && (di==0 || di==1)){
            di=1;
            dp[i]=dp[i-1]+a[i];
        }else if(a[i]<a[i-1]){
            if(di==2){
                dp[i]=dp[i-1]+a[i];
                mar[i]=1;
            }else if(di==1){
                dp[i]=dp[i-1]+a[i];
                di=2;
                mar[i]=1;
            }
        }else if(a[i]==a[i-1]){
            dp[i]=dp[i-1]+a[i];
            mar[i]=1;
        }else{
            dp[i]=a[i]+a[i-1]+(mi*(i-1-ze-1));
        }
        mi=min(a[i],mi);
    }
    if(!cnt){
        printf("-1\n");
        return 0;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",dp[i]);
    // }
    //  printf("\n");
    // for(int i=1;i<=n;i++){
    //     printf("%d ",b[i]);
    // }
    // printf("\n");
    mi=1e9,di=0,ze=0;
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            re[i]=0;
            ze=i;
            mi=1e9;
            continue;
        }
        if(b[i]>b[i-1] && (di==0 || di==1)){
            di=1;
            re[i]=re[i-1]+b[i];
        }else if(b[i]<b[i-1]){
            if(di==2){
                re[i]=re[i-1]+b[i];
                mab[i]=1;
            }else if(di==1){
                re[i]=re[i-1]+b[i];
                di=2;
                mab[i]=1;
            }
        }else if(b[i]==b[i-1]){
            re[i]=re[i-1]+b[i];
            mab[i]=1;
        }else{
            re[i]=b[i]+b[i-1]+(mi*(i-1-ze-1));
        }
        mi=min(b[i],mi);
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",re[i]);
    // }
    // printf("\n");
    int j=n;
    for(int i=1;i<=n/2;i++){
        swap(re[j],re[i]);
        swap(mab[j],mab[i]);
        j--;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",re[i]);
    // }
    // printf("\n");
    int now,ma,l,r;
    for(int i=2;i<n;i++){
        if(a[i]==0 || dp[i-1]==0 || re[i+1]==0) continue;
        l=a[i-1]-1;
        if(mar[i-1])l=a[i-1];
        r=a[i+1]-1;
        if(mab[i+1])r=a[i+1];
        if(l==0 || r==0) continue;
        // printf("%d %d %d\n",l,r,i);
        // printf("%d %d %d\n",dp[i-1],re[i+1],(min(a[i],min(l,r))));
        now=dp[i-1]+re[i+1]+(min(a[i],min(l,r)));
        if(ans<now){
            ans=now;
            ma=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}

