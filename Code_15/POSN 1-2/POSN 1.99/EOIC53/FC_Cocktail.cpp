/*
    TASK:FC_Cocktail
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100],cou[100100];
int main(){
    long long n,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        cou[a[i]]++;
    }
    /*for(i=1;i<=n;i++){
        printf("%d\n",cou[i]);
    }*/
    long long w,ans=0;
    scanf("%lld",&w);
    for(i=0;i<n;i++){
            //printf("-%d-%d\n",ans,a[i]);
        if(a[i]*2==w){
            //printf("\n%d %d",a[i],cou[a[i]]);
            //printf("%d\n",cou[w-a[i]]);
            ans+=(cou[a[i]]*(cou[a[i]]-1)/2);
            //printf("%d\n",ans);
            cou[a[i]]=0;
            continue;
            //printf("--%d %d\n",a[i],w-a[i]);
        }
        if(a[i]<=w && cou[a[i]] && cou[w-a[i]]){
            ans+=cou[w-a[i]]*cou[a[i]];
            cou[w-a[i]]=0;
            cou[a[i]]=0;
            //printf("%d %d\n",a[i],w-a[i]);
        }
    }
    printf("%lld",ans);
}
//7 2 5 3 4 3 3 4 4
