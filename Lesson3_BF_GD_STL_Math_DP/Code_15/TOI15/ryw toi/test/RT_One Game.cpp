/*
    TASK:RT_One Game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int main(){
    int i,j,ans=0,num,n,t,ball=0;;
    for(i=2;i<=100000;i++){
        dp[i]=1e9;
    }
    scanf("%d %d",&n,&t);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(dp[num]!=1e9){
            ans+=dp[num],ball++;
        }
        else{
            dp[num]=1;
            for(j=2*num;j<=100000;j+=num)
                dp[j]=min(dp[j],dp[num]+dp[j/num]);
        }
    }
    if(t==1)printf("%d\n",ball);
    else printf("%d %d\n",ball,ans);
    return 0;
}
