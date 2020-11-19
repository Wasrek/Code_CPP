/*
    TASK:RT_Median
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,i;
    float ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n%2){
        ans=a[n/2+1];
        printf("%.1f\n",ans);
        return 0;
    }
    ans=(float)(a[n/2]+a[n/2+1])/2;
    printf("%.1f\n",ans);
}
