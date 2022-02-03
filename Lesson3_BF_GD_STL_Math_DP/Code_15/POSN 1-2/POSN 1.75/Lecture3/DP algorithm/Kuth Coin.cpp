/*
    TASK:Kuth Coin
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[7][100100];
int main()
{
    int q,i,j,k,l;
    scanf("%d",&q);
    for(i=0;i<5;i++){
        dp[i][0]=1;
    }
    for(j=1;j<=100100;j++){
        k=0;
        k+=dp[0][j-1],dp[0][j]=(k+1000003)%1000003;
        if(j-5>=0){k+=dp[1][j-5],dp[1][j]=(k+1000003)%1000003;}else{dp[1][j]=dp[0][j];}
        if(j-10>=0){k+=dp[2][j-10],dp[2][j]=(k+1000003)%1000003;}else{dp[2][j]=dp[1][j];}
        if(j-25>=0){k+=dp[3][j-25],dp[3][j]=(k+1000003)%1000003;}else{dp[3][j]=dp[2][j];}
        if(j-50>=0){k+=dp[4][j-50],dp[4][j]=(k+1000003)%1000003;}else{dp[4][j]=dp[3][j];}
    }
    //printf("%d",dp[1][1]);
    while(q--){
        scanf("%d",&k);
        /*if(k>=50){
            i=4;
        }else
        if(k>=25){
            i=3;
        }else
        if(k>=10){
            i=2;
        }else
        if(k>=5){
            i=1;
        }else
        if(k>=1){
            i=0;
        }*/
        printf("%d\n",dp[4][k]);
    }
    return 0;
}
