/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[2][500100][3],ma[2][500100][4];
int main()
{
    int n,m,mi,x,y,ii,jj,k;
    char now;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&now);
            if(now=='R'){
                a[i%2][j][0]=1;
                a[i%2][j][1]=0;
            }else{
                a[i%2][j][1]=1;
                a[i%2][j][0]=0;
            }
            ma[i%2][j][0]=0;
            if(i==1){
                continue;
            }
            x=min(a[(i+1)%2][j][1]+a[i%2][j][1],a[(i+1)%2][j][0]+a[i%2][j][0]);
            y=min(a[i%2][j-1][1]+a[i%2][j][1],a[i%2][j-1][0]+a[i%2][j][0]);
            if(ma[(i+1)%2][j][0]){
                ii=(i+1)%2;
                jj=j;
                k=min(ma[ii][jj][1]+a[i%2][j][1],ma[ii][jj][2]+a[i%2][j][0]);
                if(k>x){
                    a[ii][jj][1]=ma[ii][jj][1];
                    a[ii][jj][0]=ma[ii][jj][2];
                    x=k;
                }
            }
            if(ma[i%2][j-1][0]){
                ii=i%2;
                jj=j-1;
                k=min(ma[ii][jj][1]+a[i%2][j][1],ma[ii][jj][2]+a[i%2][j][0]);
                if(k>x){
                    a[ii][jj][1]=ma[ii][jj][1];
                    a[ii][jj][0]=ma[ii][jj][2];
                    y=k;
                }
            }
            if(x==y){
                ma[i%2][j][0]=1;
                ma[i%2][j][1]=a[i%2][j][1]+a[(i+1)%2][j][1];
                ma[i%2][j][2]=a[i%2][j][0]+a[(i+1)%2][j][0];
            }else{
                ma[i%2][j][0]=0;
            }
            if(x>y){
                a[i%2][j][1]+=a[(i+1)%2][j][1];
                a[i%2][j][0]+=a[(i+1)%2][j][0];
            }else{
                a[i%2][j][1]+=a[i%2][j-1][1];
                a[i%2][j][0]+=a[i%2][j-1][0];
            }
        }
        // for(int k=1;k<=m;k++){
        //         printf(" (%d %d)",a[i%2][k][0],a[i%2][k][1]);
        // }
        // printf("\n");
    }
    mi=min(a[n%2][m][0],a[n%2][m][1]);
    printf("%d\n",mi*2);
    int pi,pj;
    pi=n,pj=m;
    // while(pi!=1 && pj!=1){

    // }
    return 0;
}