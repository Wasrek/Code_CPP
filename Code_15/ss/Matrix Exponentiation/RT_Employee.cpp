/*
    TASK:RT_Employee
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    double M[255][255];
};
int n;
A c;
A mul(A a,A b){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c.M[i][j]=0;
            for(int k=1;k<=n;k++){
                c.M[i][j]+=a.M[i][k]*b.M[k][j];
            }
        }
    }
    return c;
}
A dp[20],ans,tmp;
int main()
{
    int t,i,j;
    scanf("%d %d",&n,&t);
    for(i=1;i<=n;i++){
        scanf("%lf",&ans.M[1][i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lf",&dp[0].M[i][j]);
        }
    }
    for(i=1;i<20;i++){
        dp[i]=mul(dp[i-1],dp[i-1]);
    }
    for(i=1;i<=n;i++){
        tmp.M[i][i]=1;
    }
    for(i=0;i<20;i++){
        if(t&(1<<i)){
            tmp = mul(tmp,dp[i]);
        }
    }
    ans = mul(ans,tmp);
    for(int i=1;i<=n;i++){
        printf("%.2lf\n",ans.M[1][i]);
    }
    return 0;
}
/*
3 1
30 40 50
0.5 0.2 0.3
0.1 0.4 0.5
0.3 0.3 0.4
*/
