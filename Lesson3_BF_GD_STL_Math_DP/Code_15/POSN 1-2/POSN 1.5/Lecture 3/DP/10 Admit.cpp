/*
    TASK:Admit
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][30],b[100100];
int dp[100100]={1};
int main()
{
    int n,len,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %s",a[i]);
    scanf(" %s",b+1);
    len=strlen(b+1);
    for(i=1;i<=len;i++){
            for(j=0;j<n;j++){
                k=strlen(a[j]);
                if(k>i) continue;
                if(!strncmp(&b[i-k+1],a[j],k))
                    dp[i]=dp[i-k];
                if(dp[i]==1)
                    break;
            }
    }
    for(i=len;i>=0;i--){
        if(dp[i]){
            printf("%d\n",i); break;
        }
    }

    return 0;
}
/*
5
A AB BBC CA BA
ABABACABAABCB
*/
