/*
    TASK:AP_Group
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
pair<int,int>a[100100];
int main()
{
    int q;
    scanf("%d",&q);
    int n,cnt=0,idx,i,num;
    while(q--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&a[i].first,&a[i].second);
            a[i].first*=-1;
        }
        sort(a,a+n);
        for(i=0; i<n; i++)
        {
            idx=upper_bound(dp,dp+cnt,a[i].second)-dp;
            if(idx==cnt)
                cnt++;
            dp[idx]=a[i].second;
        }
        printf("%d\n",cnt);
    }
}
/*
2
3
1 3
3 4
2 2
6
3 4
4 6
11 3
15 2
7 5
1 8
*/
