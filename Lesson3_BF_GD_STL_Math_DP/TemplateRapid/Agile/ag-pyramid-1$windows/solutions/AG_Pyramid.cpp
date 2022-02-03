/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
#define N 10000000
int dp[N+10];
int main()
{
    int q;
    scanf("%d",&q);
    int zD = 1;
    int zABC = 0;
    for (int i = 1; i <= N; i++) {
	    int nzD = zABC * 3LL % MOD;
	    int nzABC = (zABC * 2LL + zD) % MOD;
	    zD = nzD;
	    zABC = nzABC;
        dp[i]=zD;
    }   
    int a;
    for(int i=1;i<=q;i++){
        cin>>a;
        cout<<dp[a]<<endl;
    }
    return 0;
}