#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ing long long
int a[100010];
int MOP(int n,int m){
    int l,r;
    int now = 2*m-a[n]+1;
    if(now<2) return -1;
    if(n==1) return now;
    if(now%2==1){
        l = MOP(n-1,now/2),r = MOP(n-1,now/2+1);
        if(l==-1 or r==-1) return -1;
        else return l+r;
    }
    if(now%2==0){
        l = MOP(n-1,now/2);
        if(l==-1) return -1;
        else      return 2*l;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n,m,ans;
        cin >> n >> m;
        for(int i=1;i<=n-1;i++)
            cin >> a[i];
        ans = MOP(n-1,m);
        cout << ans << endl;
    }

    return 0;
}
