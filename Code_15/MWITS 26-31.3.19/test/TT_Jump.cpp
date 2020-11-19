/*
    TASK:ข้อที่หนึ่ง ตังตังกระโดด (TT_Jump)
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int d[1010],dp[20100];
int main(){
    int q,a,b,c,i,j,mi;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        mi=1<<30;
        for(i=1;i<=c;i++){scanf("%d",&d[i]);mi=min(mi,d[i]);}
        if(a>b)swap(a,b);
        for(i=1;i<=b;i++)dp[i]=1<<30;
        dp[a]=0;
        for(i=a;i<=b-mi;i++){
            if(dp[i]==1<<30)continue;;
            for(j=1;j<=c;j++){
                if(i+d[j]>b)continue;
                dp[i+d[j]]=min(dp[i+d[j]],dp[i]+1);
            }
        }
        //for(i=a;i<=b;i++)printf("%d\n",dp[i]);
        if(dp[b]==1<<30)printf("-1\n");
        else
        printf("%d\n",dp[b]);
        memset(dp,0,sizeof dp);
    }
}
