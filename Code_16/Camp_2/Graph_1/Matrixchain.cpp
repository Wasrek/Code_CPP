/*
    TASK:Matrixchain
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long row[15],col[15],dp[15][15],path[15][15];
void pri(int l,int r){
    // printf("%d %d\n",l,r);
    if(l==r){
        printf("A%d",l);
        return ;
    }
    int k=path[l][r];
    printf("(");
    pri(l,k);
    printf(" x ");
    pri(k+1,r);
    printf(")");
    return ;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&row[i],&col[i]);
    }
    long long j,l,mi,now;
    for(long long k=2;k<=n;k++){
        for(long long i=1;i<=n-k+1;i++){
            j=i+k-1;
            mi=1<<30;
            for(long long l=i;l<j;l++){
                now=dp[i][l]+dp[l+1][j]+(row[i]*col[l]*col[j]);
                if(now<mi){
                    mi=now;
                    path[i][j]=l;
                }
                dp[i][j]=mi;
            }

        }
    }
    printf("%d\n",dp[1][n]);
    pri(1,n);
    return 0;
}