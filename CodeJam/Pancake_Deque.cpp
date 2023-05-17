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
deque<int> dq;
int main()
{
    int q,n,a,ma,ans=0;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&a);
            dq.push_back(a);
        }
        ma=0,ans=0;
        for(int j=1;j<=n;j++){
            if(dq.front() < dq.back()){
                if(ma<=dq.front()){
                    ans++;
                    ma=max(ma,dq.front());
                }
                dq.pop_front();
            }else{
                if(ma<=dq.back()){
                    ans++;
                    ma=max(ma,dq.back());
                }
                dq.pop_back();
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}