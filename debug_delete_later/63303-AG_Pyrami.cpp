#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN = 1e7+10, M = 1e9+7;
int dp[mxN],qs[mxN];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q,i,n;
    dp[2] = qs[2] = 3;
    for(i=3;i<=mxN;i++){
        qs[i] = (qs[i-1]*3)%M;
        dp[i] = (qs[i-1]*2)%M;
    }
    cin >> q;
    while(q--){
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
