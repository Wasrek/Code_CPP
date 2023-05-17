/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010],b[2010][2010];
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        scanf("%s",a[i]+1);
        for(int j=1;j<=c;j++){
            b[i+j][j]=a[i][j];
        }
    }
    for(int i=2;i<=r+c;i++){
        for(int j=1;j<=c;j++){
            printf("%c",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}