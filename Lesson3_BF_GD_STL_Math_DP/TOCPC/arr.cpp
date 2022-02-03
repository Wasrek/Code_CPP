/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],la[1000010],dp[1000010],cnt[1000010];
int main()
{
    int n,k,midp=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ch,ans=1e9,cou=0,la;
    for(int i=0;i<(1<<n);i++){
        for(int i=0;i<n;i++){
            cnt[a[i]]=0;
        }
        ch=1;cou=0;
        for(int j=0;j<n;j++){
            if(i & 1<<j){
                cou++;
                if(cnt[a[j]]>1 && la!=a[j]){
                    break;
                    ch=0;
                }
                cnt[a[i]]++;
                la=a[j];
            }
        }
        if(ch){
            ans=min(ans,n-cou);
        }
    }
    printf("%d\n",ans);
    return 0;
}