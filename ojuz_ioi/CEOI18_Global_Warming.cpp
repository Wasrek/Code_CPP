/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],lis1[200010],lis2[200010],L[200010],R[200010];
int main()
{
    int idx,n,x,cnt=0,ans=0;
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        idx=lower_bound(lis1,lis1+cnt,a[i])-lis1;
        if(idx==cnt) cnt++;
        lis1[idx]=a[i];
        L[i]=idx+1;
    }
    ans=cnt;
    cnt=0;
    int tor;
    for(int i=n;i>=1;i--){
        a[i]*=-1;
        tor=lower_bound(lis2,lis2+cnt,a[i]+x)-lis2;
        ans=max(ans,L[i]+tor);
        idx=lower_bound(lis2,lis2+cnt,a[i])-lis2;
        if(idx==cnt) cnt++;
        lis2[idx]=a[i];
    }
    printf("%d\n",ans);
    return 0;
}