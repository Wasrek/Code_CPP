/*
    TASK:Abate Sequence
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
vector<int> v[100100],ans;
int main()
{
    int n,cnt=0,num,idx,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        num=num*(-1);
        idx=upper_bound(dp,dp+cnt,num)-dp;
        if(idx-1>=0 && dp[idx-1]==num) continue;
        if(idx == cnt)
            cnt++;
        dp[idx]=num;
        v[idx].push_back(num);
    }
    printf("%d\n",cnt);
    num = v[cnt-1][0],ans.push_back(num);
    for(i=cnt-2;i>=0;i--){
        for(auto x: v[i]){
            if(x<num){
                num=x;ans.push_back(num);break;
            }
        }
    }
    for(i=cnt-1;i>=0;i--)
        printf("%d ",ans[i]*-1);
    return 0;
}
