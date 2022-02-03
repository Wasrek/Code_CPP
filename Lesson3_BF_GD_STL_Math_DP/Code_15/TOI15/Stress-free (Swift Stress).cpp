/*
    TASK:Stress-free (Swift Stress)
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dp1[2010][2010],dp2[2010][2010];
long long play1(int a,int b){
    if(dp1[a][b]!=-1)return dp1[a][b];
    long long sum=0;
    if(a==1 && b==0)return 1;
    if(a-1>0 && a-1>b)
        sum+=play1(a-1,b),sum%=1000000007;
    if(b-1>=0)
        sum+=play1(a,b-1),sum%=1000000007;
    return dp1[a][b]=sum;
}
long long play2(int a,int b){
    if(dp2[a][b]!=-1)return dp2[a][b];
    long long sum=0;
    if(a==0 && b==0)return 1;
    if(a-1>=0)
        sum+=play2(a-1,b),sum%=1000000007;
    if(b-1>=0 && b-1>=a)
        sum+=play2(a,b-1),sum%=1000000007;
    return dp2[a][b]=sum;
}
int main(){
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d-%d",&a,&b);
        printf("%lld %lld\n",play1(a,b),play2(a,b));
    }
    return 0;
}
