/*
    TASK:RT_Move Person
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[5100],b[5100],dp[5100];
map<int,int>mp;
int main(){
    int n,k,i,cnt=0,idx;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]),b[i]=a[i];
    sort(b,b+n);
    for(i=0;i<n;i++)
        mp[b[i]]=i/k;
    for(i=0;i<n;i++){
        idx=upper_bound(dp,dp+cnt,mp[a[i]])-dp;
        if(idx==cnt)cnt++;
        dp[idx]=mp[a[i]];
    }
    printf("%d\n",n-cnt);
    return 0;
}

