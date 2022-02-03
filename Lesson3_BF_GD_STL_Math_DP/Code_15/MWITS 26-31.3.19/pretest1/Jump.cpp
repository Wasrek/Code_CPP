/*
    TASK:Jump
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[30100],m[60100],dp[60100];
int main(){
    int n,k,i,Ma=0,ans=0,l;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);Ma=max(Ma,a[i]);m[a[i]]=1;}
    for(i=1;i<=Ma;i++){
        if(m[i]){dp[i]=dp[i-1]+1;}else dp[i]=dp[i-1];
        //printf("%d ",dp[i]);
    }
    //printf("\n");
    for(i=1;i<=n;i++){
        //l=ans;
        ans=max(ans,dp[a[i]+k]-dp[a[i]]);
        //printf("   %d %d %d %d\n",ans,a[i],dp[a[i]+k],dp[a[i]]);
    }
    printf("%d\n",ans);
}
/*
11 6
3
6
7
9
10
11
13
16
18
19
20
*/
