/*
    TASK:RT_Buy2Get1Free
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    sort(a+1,a+1+n);
    for(i=n-2;i>=1;i-=3){
        ans-=a[i];
    }
    printf("%d\n",ans);
}
