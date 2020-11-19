/*
    TASK:Key TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010],c[2020],dp[2020][2020];
int main()
{
    int i,j,k,lena,lenb,len;
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    scanf("%d",&k);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    while(k--)
    {
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        scanf(" %s",c+1);
        len=strlen(c+1);
        for(i=0;i<=lena;i++){
            for(j=0;j<=lenb;j++){
                if(j>0 && b[j]==c[i+j])dp[i][j]=max(dp[i][j],dp[i][j-1]);
                if(i>0 && a[i]==c[i+j])dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        if(dp[lena][lenb])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
