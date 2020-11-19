/*
    TASK:Frustrate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
int dp[100100];
int main()
{
   int i,a,b,n,q;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      scanf("%d",&a);
      dp[i] = dp[i-1]+a;
   }
   scanf("%d",&q);
   while(q--)
   {
      scanf("%d %d",&a,&b);
      printf("%d\n",dp[b]-dp[a-1]);
   }
   return 0;
}
