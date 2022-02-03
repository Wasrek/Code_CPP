/*
    TASK:Swift Friend
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long mark[23][300010];
char s[25];
int main(){
    long long n,l,i,j,len,m,ans=0;
    scanf("%lld %lld",&n,&l);
    for(i=1;i<=n;i++){
        scanf(" %s",s);
        len=strlen(s);
        for(j=1;j<=20;j++)mark[j][i]=mark[j][i-1];
        mark[len][i]++;
        if(i-l-1<0)m=0;
        else m=i-l-1;
//        for(j=1;j<=20;j++)printf("%d ",mark[j][i]);
//        printf("\n");
//        printf("%d %d\n",mark[len][i-1],m);
        ans+=mark[len][i-1]-mark[len][m];
    }
    printf("%lld\n",ans);
}
/*
5 2
GOLF
JUMP
FOG
BEAM
TAN
*/
