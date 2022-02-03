/*
    TASK:RT_High Jump
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long w[610][610],dis[610][610];
int main(){
    long long n,i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=2*n;i++){
        for(j=1;j<=2*n;j++){
            scanf("%lld",&w[i][j]);
            if(i<j)dis[i][j]=1<<30;
            else dis[i][j]=w[i][j];
        }
    }//i>j
    //printf("%d",dis[2*n][2]);
    for(k=2;k<=2*n;k++){
        for(i=2;i<=2*n;i++){
            for(j=2;j<=2*n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                //printf(" - %lld %lld -   %lld\n",i,j,dis[i][k]+dis[k][j]);
            }
        }
    }
    printf("%lld",dis[2*n][2]);
}
/*
5
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 14 0 0 0 0 0 0 0 0
0 30 15 0 0 0 0 0 0 0
0 41 21 13 0 0 0 0 0 0
0 51 42 22 11 0 0 0 0 0
0 75 58 34 28 12 0 0 0 0
0 67 71 44 37 23 14 0 0 0
0 95 77 51 41 44 28 15 0 0
0 96 94 66 72 41 37 30 11 0
*/
