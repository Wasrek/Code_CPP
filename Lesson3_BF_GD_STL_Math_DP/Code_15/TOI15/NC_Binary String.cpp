/*
    TASK:NC_Binary String
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int has[21][1<<21],dp[100010];
char s[21],a[100010];
int main(){
    int n,len,i,sum,j;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",s);
        len=strlen(s);
        sum=0;j=0;
        for(i=len-1;i>=0;i--){
            sum+=((1<<j)*(s[i]-'0'));
            j++;
        }
        has[len][sum]=1;
    }
    scanf(" %s",a+1);
    len=strlen(a+1);
    dp[0]=1;
}
