/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[50][50][50][50],b[50][50][50][50],qs[50][50];
char s[50][50];
int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf(" %s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            qs[i][j]=s[i][j]-'0'+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int ii=i;ii<=n;ii++){
                for(int jj=j;jj<=m;jj++){
                    if((qs[ii][jj]-qs[ii][j-1]-qs[i-1][jj]+qs[i-1][j-1])==0){
                        a[i][j][ii][jj]=1;
                    }else a[i][j][ii][jj]=0;
                }
            }
        }
    }

    //b[i][j][k][l] ผลรวมของ a[i][j][k][l] ทุกตัวใน i j l k วิ่งถึง 0 0
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=m;l++){
                    b[i+1][j+1][k+1][l+1]
                    =b[i][j+1][k+1][l+1]//left+up
                    +b[i+1][j][k+1][l+1]
                    +b[i+1][j+1][k][l+1]
                    +b[i+1][j+1][k+1][l]
                    -b[i][j][k+1][l+1]//upper left 4Choose2
                    -b[i][j+1][k][l+1]
                    -b[i][j+1][k+1][l]
                    -b[i+1][j][k][l+1]
                    -b[i+1][j][k+1][l]
                    -b[i+1][j+1][k][l]
                    +b[i+1][j][k][l]
                    +b[i][j+1][k][l]
                    +b[i][j][k+1][l]
                    +b[i][j][k][l+1]
                    -b[i][j][k][l]
                    +a[i][j][k][l];
                }
            }
        }
    }
    int i,j,k,l;
    while(q--){
        scanf("%d %d %d %d",&i,&j,&k,&l);
        printf("%d\n",b[k+1][l+1][k+1][l+1]
                -b[i][l+1][k+1][l+1]
                -b[k+1][j][k+1][l+1]
                -b[k+1][l+1][i][l+1]
                -b[k+1][l+1][k+1][j]
                +b[i][j][k+1][l+1]
                +b[i][l+1][i][l+1]
                +b[i][l+1][k+1][j]
                +b[k+1][j][i][l+1]
                +b[k+1][j][k+1][j]
                +b[k+1][l+1][i][j]
                -b[k+1][j][i][j]
                -b[i][l+1][i][j]
                -b[i][j][k+1][j]
                -b[i][j][i][l+1]
                +b[i][j][i][j]);
    }
    return 0;
}