/*
    TASK:RT_Makato1
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],dp[100100];
int main(){
    int n,q,i,x,y;
    scanf("%d %d %d",&n,&q,&a[1]);
    dp[1]=a[1];
    for(i=2;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=dp[i-1]^a[i];
    }
    while(q--){
        scanf("%d %d",&x,&y);
        printf("%d\n",dp[y]^dp[x-1]);
    }
    return 0;
}
