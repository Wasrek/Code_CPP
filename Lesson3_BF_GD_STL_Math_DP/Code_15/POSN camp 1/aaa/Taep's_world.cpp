/*
    TASK:Taep's world
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010],a[1000100];
int main()
{
   long long r,c,k,i,j,num,cou=0;
   scanf("%lld %lld %lld",&r,&c,&k);
   for(i=1;i<=r;i++){
    for(j=1;j<=c;j++){
        scanf("%lld",&num);
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+num;
    }
   }
   for(i=1;i<=r-k+1;i++){
    for(j=1;j<=c-k+1;j++)
        a[cou++]=dp[i+k-1][j+k-1]-dp[i+k-1][j-1]-dp[i-1][j+k-1]+dp[i-1][j-1];
   }
   sort(a,a+cou);
   printf("%lld ",a[cou-1]);
   for(i=cou-2;i>=0;i--){
    if(a[i]!=a[i+1]){
        printf("%lld\n",a[i]);
        return 0;
    }
   }
}
/*
4 6 3
10 2 1 3 2 1
3 5 6 2 3 1
2 3 1 4 12 1
1 2 3 4 5 6
*/
