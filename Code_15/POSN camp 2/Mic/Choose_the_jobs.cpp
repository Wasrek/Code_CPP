/*
    TASK:Choose the jobs
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e,w;
    bool operator <(const A&o)const{
        if(e!=o.e) return e < o.e;
        return s < o.s;
    }
};
A a[100100];
int b[100100],dp[100100];
int main(){
    int n,i,idx;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].w);
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        b[i]=a[i].e;
    }
    for(i=1;i<=n;i++){
        idx=lower_bound(b+1,b+n+1,a[i].s)-(b+1);
        // cout << idx <<endl;
        dp[i]=max(dp[i-1],dp[idx]+a[i].w);
    }
    printf("%d\n",dp[n]);
    return 0;
}
