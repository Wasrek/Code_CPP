/*
    TASK:Peatt Markets
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> h;
int main()
{
    int q,n,m,k,num,opr,sum=0;
    long long ans;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d",&n,&m,&k);
        sum=0,ans=0;
        while(n--)
        {
            scanf("%d",&num);
            h.push(-num);
        }
        while(m--)
        {
            scanf("%d",&opr);
            if(opr==1){
                scanf("%d",&num);
                h.push(-num+sum);
            }
            else if(opr==2){
                sum+=k;
            }
            else if(opr==3){
                if(!h.empty())
                    h.pop();
            }
        }
        printf("%d ",h.size());
        while(!h.empty()){
            ans += -h.top()+sum;
            h.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
