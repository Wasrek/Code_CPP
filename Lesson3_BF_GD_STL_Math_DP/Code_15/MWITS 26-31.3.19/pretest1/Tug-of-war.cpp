/*
    TASK:Tug-of-war
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int b[2100],a[2100];
int main(){
    int i,n,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(i=1;i<=n;i++){
        ans+=abs(b[i]-a[i]);
    }
    printf("%d\n",ans);
}
