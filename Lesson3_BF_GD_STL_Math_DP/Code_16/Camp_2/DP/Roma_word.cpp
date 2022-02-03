/*
    TASK:Roma word
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[2010],b[2010],c[1010];
int dp[2010][2010],path[2010][2010];
int main()
{
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    int lena,lenb;
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                path[i][j]=1;
            }else dp[i][j]=dp[i][j-1],path[i][j]=2;
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                path[i][j]=3;
            }
        }
    }
    int i=lena,j=lenb;
    int cnt=dp[lena][lenb];
    while(i>0 && j>0){
        if(path[i][j]==3){
            c[cnt--]=a[i];
            i--,j--;
            continue;
        }
        if(path[i][j]==2){
            j--;
        }else i--;
    }
    printf("%d\n",dp[lena][lenb]);
    if(!dp[lena][lenb]){
        printf("No Roma word\n");
        return 0;
    }
    for(int i=1;i<=dp[lena][lenb];i++){
        printf("%c",c[i]);
    }
    return 0;
}