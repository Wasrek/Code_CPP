/*
    TASK:Pipe
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y,v;
};
A a[15100];
priority_queue< int > h;
int main()
{
    long long n,k,g,now,mi,imi,ans=0;
    scanf("%lld %lld",&n,&k);
    g=n-k;
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].v=1<<30;
    }
    for(int i=1;i<n;i++){
        mi=1<<30;
        for(int j=i+1;j<=n;j++){
            now=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
            if(now<a[j].v)a[j].v=now;
            if(a[j].v<mi) mi=a[j].v,imi=j;
        }
        // printf("%d ",mi);
        swap(a[i+1],a[imi]);
    }
    // printf("\n");
    // for(int i=1;i<=n;i++) printf("%d ",a[i].v);
    for(int i=1;i<=n;i++) h.push(-a[i].v);
    while(!h.empty() && g--)ans+=h.top()*(-1),h.pop();
    printf("%lld\n",ans);
    return 0;   
}