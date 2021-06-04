/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y,a;
    bool operator <(const A & o) const{
        return x<o.x; 
    }
};
struct Line{
    long long m,c;
    long long finval(int x){
        return m*x+c;
    }
    long double inters(Line l){
        return (long double)(c-l.c)/(l.m-m);
    }
};
Line line;
deque<Line> dq;
A rect[1000010];
int main()
{
    long long n,x,y,a,now,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld %lld",&rect[i].x,&rect[i].y,&rect[i].a);
    }
    sort(rect+1,rect+1+n);
    //xi*yi-ai+max(-xj*yi+dp[j])
    dq.push_back({0,0});
    for(int i=1;i<=n;i++){
        x=rect[i].x;y=rect[i].y;a=rect[i].a;
        // printf("%lld %lld %lld\n",x,y,a);
        while(dq.size()>1 && dq.front().inters(dq[1])>=y) dq.pop_front();
        now=(1LL*x*y)-a+dq.front().finval(y);
        // printf("front %lld %lld now %lld\n",dq.front().m,dq.front().c,now);
        ans=max(ans,now);
        line={-1LL*x,now};
        // printf("line %lld %lld\n",-1LL*x,now);
        while(dq.size()>1 && dq.back().inters(dq[dq.size()-2])<=line.inters(dq[dq.size()-2])) dq.pop_back();
        dq.push_back(line);
    }
    printf("%lld\n",ans);
    return 0;
}