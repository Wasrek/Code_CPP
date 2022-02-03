/*
    TASK:Barrier TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[6000100];
deque<long long> dq;
int main(){
    long long n,w,i,len,ma=0,ch=1;
    scanf("%lld %lld",&n,&w);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>0)ch=0;
        a[i]+=a[i-1];
    }
    if(ch){
        printf("0\n0\n");
        return 0;
    }
     dq.push_back(0);
    for(i=1;i<=n;i++){
        while(!dq.empty() && i-dq.front()>w)dq.pop_front();
        if(a[i]-a[dq.front()]==ma)len=min(len,i-dq.front());
        if(a[i]-a[dq.front()]>ma){
           ma=a[i]-a[dq.front()];
           len=i-dq.front();
        }
        while(!dq.empty() && a[i]<=a[dq.back()])dq.pop_back();
        dq.push_back(i);
    }
    printf("%lld\n%lld\n",ma,len);

}
/*
ติดกัน k ตัวนึกถึง sliding window deque
เกิน 4 ตัว pop front(i-dq.front()>k) ทิ้ง pop back while (qs[i]<qs[dq.back()]) ถ้าค่าลด
เป็น deque of index
ans=qs[dq.back()]-qs[dq.front()]
len=dq.back()-dq.front();
*/
