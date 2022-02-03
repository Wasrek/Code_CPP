/*
    TASK:Key TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010],c[2010];
int dp[1010][1010];
int main(){
    int q,i,j,lena,lenb;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    scanf("%d",&q);
    while(q--){
        dp[0][0]=1;
        scanf(" %s",c+1);
        for(i=1;i<=lena;i++){
            if(a[i]==c[i])dp[i][0]=1;
            else break;
        }
        for(j=1;j<=lenb;j++){
            if(b[j]==c[j])dp[0][j]=1;
            else break;
        }
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(b[j]==c[i+j])dp[i][j]=max(dp[i][j],dp[i][j-1]);
                if(a[i]==c[i+j])dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        if(dp[lena][lenb])printf("Yes\n");
        else printf("No\n");
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
dp[1000][1000] dp[i][j]
if we get string b1-bj a1-ai
dp[0][0]=1;
0-lena
0-lenb
dp[0][1] for first case BAABB B[1]='A' we have only 1 B
    A  B

B
A
B
if not the after also can't be
b[j]==c[i+j] from left
a[i]==c[i+j] from up
*/
