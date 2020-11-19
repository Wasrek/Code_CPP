/*
    TASK:FC_Jewel7
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,i,j;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
priority_queue<A > h;
long long a[5010],mark[5010];
int main(){
    long long ans=0,n,i,now,qs=0,k,s=1;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        now=a[i];
        if(now<=0 && qs>0){h.push({qs,s,i-1}),qs=0;s=i+1;continue;}
        if(now<=0 && qs<=0){qs=0;s=i+1;continue;}
        qs+=now;
    }
    h.push({qs,s,n});
    while(!h.empty() && k--){
        ans+=h.top().w;
        mark[h.top().i]=1;
        mark[h.top().j+1]=-1;
        h.pop();
    }
    long long sum=0,ma=0;
    for(i=1;i<=n;i++){
       mark[i]+=mark[i-1];
//       printf("%lld ",mark[i]);
    }
    //printf("\n");
    mark[n+1]=1;
    for(i=1;i<=n;i++){
       if(mark[i])sum=0,ma=0;
       if(!mark[i]){
        sum+=a[i];
        if(mark[i+1]){
            ans+=ma;
            sum=0;ma=0;
        }
       }
       if(sum>ma)ma=sum;
//       printf("%lld\n",sum);
    }
    printf("%lld",ans);
}
/*
11 2
1 2 3 4 -5 6 -1 -2 -3 8 9
*/
