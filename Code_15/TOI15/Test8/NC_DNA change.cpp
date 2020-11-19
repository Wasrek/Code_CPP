/*
    TASK:NC_DNA change
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char str1[10010],str2[5010];
int dp[5][10010];
int main(){
    int i,j,lena,lenb;
    scanf(" %s",str1);
    scanf(" %s",str2);
    lena=strlen(str1);
    lenb=strlen(str2);
    for(i=0;i<lena;i++){
        if(str1[i]=='A')str1[i]=0;
        else if(str1[i]=='C')str1[i]=1;
        else if(str1[i]=='G')str1[i]=2;
        else if(str1[i]=='T')str1[i]=3;
    }
    for(i=0;i<lenb;i++){
        if(str2[i]=='A')str2[i]=0;
        else if(str2[i]=='C')str2[i]=1;
        else if(str2[i]=='G')str2[i]=2;
        else if(str2[i]=='T')str2[i]=3;
    }
    for(i=0;i<lenb;i++){
        for(j=0;j<4;j++){
            dp[j][i]=dp[j][i-1];
        }
        dp[str2[i+1]][i]=i+1;
    }

}
