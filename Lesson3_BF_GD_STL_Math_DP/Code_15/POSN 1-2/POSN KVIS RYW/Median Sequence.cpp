/*
    TASK:Median Sequence
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int l[200100],r[200100],a[200100];
int main(){
    int n,z,i,mid,sum;
    long long ans=0;
    scanf("%d %d",&n,&z);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==z)
            mid=i;
    }
    l[100000]=r[100000]=1;
    sum=0;
    for(i=mid-1;i>=0;i--){
        if(a[i]<z)sum--;
        if(a[i]>z)sum++;
        l[100000+sum]++;
    }
    sum=0;
    for(i=mid+1;i<n;i++){
        if(a[i]<z)sum--;
        if(a[i]>z) sum++;
        r[100000+sum]++;
    }
    for(i=0;i<=200000;i++){
        ans+=(long long)l[i]*r[200000-i];
    }
    printf("%lld\n",ans);
    return 0;
}
