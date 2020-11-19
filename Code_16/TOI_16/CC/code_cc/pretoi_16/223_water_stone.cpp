/*
    TASK:น ้ำหยดลงหินทุกวัน หินมันยังกร่อน
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char c[7010][7010];
int bg[2][7010],qs[7010];
int main()
{
    int n,m,sum=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",c[i]+1);
        for(int j=1;j<=m;j++){
            bg[i%2][j]=c[i][j]-'0';
            if(bg[i%2][j]) bg[i%2][j]=min(bg[(i-1)%2][j],min(bg[i%2][j-1],bg[(i-1)%2][j-1]))+1;
            qs[bg[i%2][j]]++;
        }
    }
    for(int i=min(n,m)-1;i>0;i--){
        qs[i]+=qs[i+1];
    }
    for(int i=1;i<=min(n,m);i++){
        printf("%d\n",qs[i]);
    }
    return 0;
}