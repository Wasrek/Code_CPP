/*
    TASK:NBK48 TOI14
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,q,i,b,up;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=n-1;i>=1;i--){
        if(a[i+1]<a[i])a[i]=a[i+1];
    }
    while(q--){
        scanf("%d",&b);
        up=upper_bound(a+1,a+1+n,b)-a;
        up--;
        printf("%d\n",up);
    }
    return 0;
}
