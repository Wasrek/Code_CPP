/*
    TASK:Fluctuate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Min,now,ans=0,n,i;
    scanf("%d %d",&n,&Min);
    for(i=1;i<n;i++){
        scanf("%d",&now);
        if(now-Min > ans)
            ans = now-Min;
        if(now<Min)
            Min=now;
    }
    printf("%d\n",ans);
    return 0;
}
