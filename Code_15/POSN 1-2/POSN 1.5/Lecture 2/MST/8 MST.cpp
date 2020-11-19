/*
    TASK: MST
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int u,v;
   double w;
   bool operator<(const A& o)const{
      return w < o.w;
   }
};
A a[600000];
int p[1010];
int fin(int i){
   if(p[i]==i) return i;
   return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,pu,pv;
    double ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d %d %lf",&a[i].u,&a[i].v,&a[i].w);
    for(i=0;i<n;i++) p[i]=i;
    sort(a,a+m);
    for(i=0;i<m;i++){
        pu=fin(a[i].u),pv=fin(a[i].v);
        if(pu!=pv){
            ans+=a[i].w;p[pu]=pv;
        }
    }
    printf("%.3lf\n",ans);

    return 0;
}
