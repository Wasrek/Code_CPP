/*
    TASK:Kylo_Ren
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main()
{
    int q,a,b,c,i,j;
    for(i=1;i<=1000000;i++)
        for(j=i;j<=1000000;j+=i)
        dp[j]++;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        for(i=a,j=0;i<=b;i++)
            if(dp[i]==c)
            j++;
        printf("%d\n",j);
    }
    return 0;
}
