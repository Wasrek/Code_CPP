/*
    TASK:Q_Atom Com
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2200000][25];
int main(){
    int t,x,y,i,j;
    scanf("%d",&t);
    dp[0][0]=1;
    for(j=1;j<=20;j++){
        dp[0][j]+=dp[0][j-1];
    }
    for(j=1;j<=20;j++){
        for(i=1;i<=(1<<20)-1;i++){
            dp[i][j]+=dp[i][j-1];
            if((1<<(j-1))<=i){
                dp[i][j]+=dp[i-(1<<(j-1))][j-1];
            }
            else{
                dp[i][j]+=dp[(1<<(j-1))-i][j-1];
            }
        }
    }
    while(t--){
        scanf("%d %d",&x,&y);
        x=abs(x);
        if(x > ((1<<20)-1)){printf("0\n");continue;}
        printf("%d\n",dp[x][y]);
    }
    return 0;
}
