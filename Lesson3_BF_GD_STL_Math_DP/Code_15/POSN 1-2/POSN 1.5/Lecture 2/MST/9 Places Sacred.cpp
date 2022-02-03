/*
    TASK: Places Sacred
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int u,v,w;
   bool operator<(const A& o)const{
      return w > o.w;//max to min
   }
};
A a[1000100];
int p[200100];
int fin(int i){
   if(p[i]==i) return i;
   return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,pu,pv;
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w),a[i].w--;
    sort(a,a+m);
    for(i=1;i<=n;i++) p[i]=i;
    for(i=0;i<m;i++){
        pu=fin(a[i].u),pv=fin(a[i].v);
        if(pu!=pv)
            ans+=a[i].w,p[pu]=pv;
    }
    printf("%lld\n",ans);

    return 0;
}
