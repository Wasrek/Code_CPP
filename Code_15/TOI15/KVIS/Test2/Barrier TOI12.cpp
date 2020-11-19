/*
    TASK:Barrier TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
deque<long long> dq;
long long a[6000100];
int main(){
    long long n,w,i,len,ma=0,ch=1;
    scanf("%lld %lld",&n,&w);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>0)ch=0;
        a[i]+=a[i-1];
    }
    if(ch){
        printf("0\n0");
        return 0;
    }
    dq.push_back(0);
    for(i=1;i<=n;i++){
        while(!dq.empty() && i-dq.front()>w)dq.pop_front();
        if(a[i]-a[dq.front()]==ma){
            len=min(len,i-dq.front());
        }
        if(a[i]-a[dq.front()]>ma){
            ma=a[i]-a[dq.front()];
            len=i-dq.front();
        }
        while(!dq.empty() && a[dq.back()]>a[i])dq.pop_back();
        dq.push_back(i);
    }
    printf("%lld\n%lld\n",ma,len);
    return 0;
}
/*
7 4
3
2
5
1
4
-7
*/
