#include<bits/stdc++.h>
using namespace std;
int a[120],n,i,ans;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++){
     scanf("%d",&a[i]);
    }
    for(i=n-2;i>=0;i--){
        if(a[i]>=a[i+1]){
            ans+=(a[i]-a[i+1]+1);
            a[i]=a[i+1]-1;
        }
    }
    printf("%d\n",ans);
}
