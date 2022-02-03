/*
    TASK:AP_Word
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2][5050];
char a[5050],b[5050];
int main(){
    int q,n,m,lena,lenb,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        scanf(" %s %s",a+1,b+1);
        lena=strlen(a+1),lenb=strlen(b+1);
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(a[i]==b[j])
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
        }
        printf("%d\n",n+m-dp[n%2][m]);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
1
8 8
POGRAMIG
ROAMMING
*/
