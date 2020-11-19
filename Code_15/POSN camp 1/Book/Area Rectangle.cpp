/*
    TASK:Area Rectangle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
   int r,c,i,j,num,q,k,l;
   scanf("%d %d",&r,&c);
   for(i=1;i<=r;i++)
   {
       for(j=1;j<=c;j++)
       {
           scanf("%d",&num);
           dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+num;
       }
   }
   scanf("%d",&q);
   while(q--){
    scanf("%d %d %d %d",&i,&j,&k,&l);
    i++,j++,k++,l++;
    printf("%d\n",dp[k][l]-dp[i-1][l]-dp[k][j-1]+dp[i-1][j-1]);
   }
   return 0;
}
