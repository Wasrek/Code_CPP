/*
    TASK:Scotch
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[5][5],mark[5][5];
long long yub(int x,int y){
    long long num=x/y;
    if(x%y) num++;
    return num%2;
}
int main(){
    long long n,a,b,ans=0,i,j;
    scanf("%lld %lld %lld",&n,&a,&b);
    for(i=1;i<=n;i++){
        if(!mark[yub(i,a)][yub(i,b)]){
            mark[yub(i,a)][yub(i,b)]=1;
            for(j=1;j<=n;j++){
                if(yub(i,a)==yub(j,a) || yub(i,b)==yub(j,b)){
                    dp[yub(i,a)][yub(i,b)]++;
                }
            }
        }
        ans+=dp[yub(i,a)][yub(i,b)];
    }
    printf("%lld\n",ans);
    return 0;
}
