/*
    TASK:Key TOI12
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010],dp[1010][1010],k[2500];
int main()
{
    int lena,lenb,len,q;
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    scanf("%d",&q);
    while(q--){
        scanf(" %s",k+1);
        len=strlen(k+1);
        if(len!=lena+lenb){
            printf("No\n");
            continue;
        }
        dp[0][0]=1;
        for(int i=0;i<=lena;i++){
            for(int j=0;j<=lenb;j++){
                if(i==0 && j==0) continue;
                dp[i][j]=0;
                if(dp[i-1][j] && a[i]==k[i+j]){
                    dp[i][j]=1;
                }
                if(dp[i][j-1] && b[j]==k[i+j]){
                    dp[i][j]=1;
                }
                // printf("%d ",dp[i][j]);
            }
            // printf("\n");
        }
        if(dp[lena][lenb]){
            printf("Yes\n");
        }else printf("No\n");
    }
    return 0;
}