/*
    TASK:RT_TriplePoints
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long fw[2][1000005];
pair<long long,long long> a[500005];
void update(long long idx1,long long idx2,long long val){
    for(;idx2<=1000000;idx2+=(idx2&-idx2))
    fw[idx1][idx2]+=val;
}
int query(long long idx1,long long idx2){
    long long sum=0;
    for(;idx2>0;idx2-=(idx2&-idx2))
        sum+=fw[idx1][idx2];
    return sum;
}
int main(){
    long long n,i,ans=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].first,&a[i].second);
    sort(a,a+n);
    for(i=0;i<n;i++)
        update(1,a[i].second+1,1);
    for(i=0;i<n;i++){
        update(1,a[i].second+1,-1);
        ans+=((n-i-1)-query(1,a[i].second))*query(0,a[i].second);
        update(0,a[i].second,1);//0=left 1=right
    }
    printf("%lld\n",ans);
    return 0;
}
