/*
    TASK:RC_Separate Ways
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[550][300][300];
struct A{
    long long i,j;
};
long long mod(long long n)
{
    return (n+1000000007)%1000000007;
}
long long chek(A i,A j){
    if((i.i==j.i && i.j==j.j+1) || (j.i+1==i.i && i.j==j.j))return 0;
    return 1;
}
vector<A> level[510];
int main()
{
    long long r,c,i,j,k,l,m;
    scanf("%lld %lld",&r,&c);
    dp[1][0][0]=1;
    for(i=r;i>0;i--){
        for(j=c;j>0;j--){
            level[i+j-1].push_back({i,j});
        }
    }
    for(i=2; i<=r+c-1; i++)
    {
        long long a=i,b=i-1;
        for(j=0; j<251; j++)
        {
            for(k=0; k<251; k++)
            {
                dp[a][j][k]=0;
            }
        }
        long long sz=level[i].size(),psz=level[i-1].size();
        for(j=0; j<sz; j++)
        {
            for(k=0; k<sz; k++)
            {
                for(l=-1; l<=1; l++) //-1 0 1 for j
                {
                    for(m=-1; m<=1; m++) //-1 0 1 for k
                    {
                        long long idx_j=j+l,idx_k=k+m;
                        if(idx_j<0 || idx_j>=psz || idx_k<0 || idx_k>=psz)
                            continue; //if outside of table
                        if(chek(level[i][j],level[i-1][idx_j]) || chek(level[i][k],level[i-1][idx_k]))
                            continue;
                        if(j==k && idx_j==idx_k)
                            continue;
                        dp[a][j][k]=mod(dp[a][j][k]+dp[b][idx_j][idx_k]);
                    }
                }
            }
        }
    }
    printf("%lld\n",dp[(r+c-1)][0][0]);
}
