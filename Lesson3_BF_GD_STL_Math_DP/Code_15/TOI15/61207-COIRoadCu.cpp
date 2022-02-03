/*
    TASK:FC_COI Road Cube
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110][10010],b[110][10010];
int main(){
    long long n,m,k,i,j,l;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(i=n-1;i>=1;i--){
        for(j=1;j<=m;j++){
            for(l=0;l<=k;l++){
                if(j+l<=m){
                if(a[i][j]+b[i+1][j+l]>b[i][j]){
                    b[i][j]=a[i][j]+b[i+1][j+l];
                }
                }
                if(j-l>0){
                if(a[i][j]+b[i+1][j-l]>b[i][j]){
                    b[i][j]=b[i+1][j-l]+a[i][j];
                }
                }
            }
        }
    }
    long long ma=0;
    for(i=1;i<=m;i++){
        ma=max(ma,b[1][i]);
    }
    printf("%lld\n",ma);
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++){
//            printf("%d ",b[i][j]);
//        }
//        printf("\n");
//    }
}
/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0
*/
