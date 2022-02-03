 /*
    TASK:NC_Monkey
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],dp[5010];
int main(){
    int n,k,i,m,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]),dp[i]=1e9;
    for(i=1;i<=n;i++){
        m=0;
        for(j=i;j>=1 && j>=i-k+1; j--){
            m=max(m,a[j]);
            dp[i]=min(dp[i],m+dp[j-1]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
/*
8 5
1
4
0
3
2
7
2
2
*/
