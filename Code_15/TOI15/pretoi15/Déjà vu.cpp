/*
    TASK:Déjà vu
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long lis[100010];
vector<long long> g[100010];
int main(){
    long long n,i,a,cou=0,idx,now,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a);
        idx=upper_bound(lis,lis+cou,a)-lis;
        if(idx==cou)cou++;
        lis[idx]=a;
        g[idx].push_back(a);
    }
    printf("%lld ",cou);
    now=g[cou-1][0];
    ans+=now;
    for(i=cou-2;i>=0;i--){
        for(auto x:g[i]){
            if(x<=now){
                now=x;
                ans+=now;
                break;
            }
        }
    }
    printf("%lld\n",ans);
}
