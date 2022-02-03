/*
    TASK:Tigger
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],a[1010],n;
int play(int now,int last){
    if(now<1||now>n) return 1000000000;
    if(now==n) return a[now];
    if(dp[now][last])return dp[now][last];
    return dp[now][last]=a[now]+min(play(now+last+1,last+1),play(now-last,last));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",play(2,1));
    return 0;
}
