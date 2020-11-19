/*
    TASK:Reap Plumtree
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010],temp[1010];
int main()
{
    int q,n,w,k,i,now,ch;
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof dp);
        scanf("%d %d",&n,&w);
        dp[0]=1;
        while(n--){
            scanf("%d",&k);
            memset(temp,0,sizeof temp);
            while(k--){
                scanf("%d",&now);
                for(i=w;i>=now;i--)
                    if(dp[i-now])
                    temp[i]=1;
            }
            for(i=0;i<=w;i++)
                dp[i]=temp[i];
            dp[0]=0;
        }
        for(i=w,ch=1;i>=0;i--){
            if(dp[i]){
                printf("%d\n",i); ch=0;break;
            }
        }
        if(ch)
            printf("-1\n");
    }

    return 0;
}
