/*
    TASK:Pairs of Four
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1005][1005];
int main(){
    int n,i,j,k,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %c",&a[i]);
    for(m=1;m<n;m++){
        for(i=0;i<n-m;i++){
            j=i+m;
            if(a[i]==a[j])dp[i][j]=dp[i+1][j-1]+1;//ดึงออก
            for(k=i;k<j;k++){//ไม่ดึง
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    printf("%d\n",dp[0][n-1]);
}
