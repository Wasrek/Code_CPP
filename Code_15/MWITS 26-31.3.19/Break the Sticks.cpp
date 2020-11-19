/*
    TASK:Break the Sticks
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[60],dp[60][60];
int main(){
    int l,p,i,j,k;
    scanf("%d %d",&l,&p);
    for(i=1;i<=p;i++){
        scanf("%d",&a[i]);
    }
    a[p+1]=l;
    for(i=0;i<=p+1;i++){
        for(j=0;j<=p+1;j++){
            if(j-i>1)dp[i][j]=1<<30;
        }
    }
    for(k=1;k<=p+1;k++){
        for(i=0;i<=p+1-k;i++){
            for(j=i+1;j<i+k;j++){
                dp[i][i+k]=min(dp[i][j]+dp[j][i+k]+a[i+k]-a[i],dp[i][i+k]);
            }
        }
    }
//    for(i=0;i<=p+1;i++){
//        for(j=0;j<=p+1;j++){
//            printf("%d ",dp[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    printf("%d\n",dp[0][p+1]);
    return 0;
}
