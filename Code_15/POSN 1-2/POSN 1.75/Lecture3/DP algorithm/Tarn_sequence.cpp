/*
    TASK:Tarn sequence
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
        idx=upper_bound(dp,dp+cnt,num)-dp;
        // cout << idx << " "<<num << endl;
        if(idx-1>=0 && dp[idx-1]==num) continue;//number is equal
        // cout << "- "<<cnt << endl;
        if(idx == cnt)
            cnt++;
        // cout << "- "<<cnt << endl;
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
        printf("%d ",ans[i]);
    return 0;
}
