/*
    TASK:NBK48 TOI14
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],qs[100100];
int main(){
    int n,q,m,l,r,mid,i,ans=0,last,ch=0;
    scanf("%d %d %d",&n,&q,&a[0]);
    for(i=1;i<n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=n-2;i>=0;i--){
        a[i]=min(a[i],a[i+1]);
    }
    while(q--){
        scanf("%d",&m);
        ans=upper_bound(a,a+n,m)-a;
        printf("%d\n",ans);
    }
}
/*
5 3
10 20 -10 30 60
*/
