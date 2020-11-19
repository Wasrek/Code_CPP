/*
    TASK:NC_X-game 2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[21][21];
int main(){
    int n,i,j;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf(" %c",&c);
            if(c=='w')a[i][j]=1;
            if(c=='b')a[i][j]=2;
        }
    }
    printf("Impossible\n");
}
