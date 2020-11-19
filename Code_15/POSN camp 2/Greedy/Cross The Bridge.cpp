/*
    TASK:Cross The Bridge
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[150];
int main(){
    int n,i,mi=10000,sum=0;
    long long ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mi=min(mi,a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    sum-=mi;
    ans=mi*(n-2)+sum;
    printf("%lld\n",ans);
}
