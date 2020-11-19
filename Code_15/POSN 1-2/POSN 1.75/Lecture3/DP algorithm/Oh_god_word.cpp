/*
    TASK:Oh! god word
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int dp[1010][1010];
int main()
{
    int i,len,j,k,Ma=1,att=0;
    scanf(" %s",a);
    len =strlen(a);
    for(i=0;i<len;i++)
        dp[i][i]=1;
    for(i=len-2;i>=0;i--)
        if(a[i]==a[i+1])
        dp[i][i+1]=1,Ma=2,att=i;
    for(k=3;k<=len;k++){
        for(i=0;i<=len-k;i++){
            j=i+k-1;
            if(dp[i+1][j-1]==1 && a[i]==a[j]){
                dp[i][j]=1;
                if(k>Ma)
                    Ma=k,att=i;
            }
        }
    }
        for(i=att;i<att+Ma;i++)
            printf("%c",a[i]);
    return 0;
}
