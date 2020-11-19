/*
    TASK:AP_Group
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e;
    bool operator < (const A&o) const{
        if(s!=o.s) return s>o.s;
        return e<o.e;
    }
};
A a[100100];
int dp[100100];
int main(){
    int q,n,idx,cnt=0,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        cnt=0;
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].s,&a[i].e);
        sort(a,a+n);
        cnt=0;
        for(i=0;i<n;i++){
            idx = upper_bound(dp,dp+cnt,a[i].e)-dp;
            if(idx==cnt)cnt++;
            dp[idx]=a[i].e;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
