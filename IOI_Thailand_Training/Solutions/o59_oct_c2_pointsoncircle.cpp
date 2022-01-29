/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dis[1010][1010],ans[1010];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&dis[i][j]);
        }
    }
    ans[0]=0;
    int ans1,ans2;
    for(int i=1;i<n;i++){
        ans1=ans[i-1]+dis[i-1][i];
        ans1+=n;ans1%=n;
        ans2=ans[i-1]-dis[i-1][i];
        ans2+=n;ans2%=n;
        ans[i]=ans1;
        for(int j=i-1;j>=0;j--){
            if(min(n-abs(ans[i]-ans[j]),abs(ans[i]-ans[j]))!=dis[i][j]){
                ans[i]=ans2;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    return 0;
}