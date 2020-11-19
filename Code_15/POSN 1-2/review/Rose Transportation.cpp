/*
    TASK:Rose Transportation
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int u,v,w;
   bool operator<(const A& o)const{
      return w > o.w;
   }
};
A a[200100];
int p[100100],node[100100];
int fin(int i){
   if(p[i]==i) return i;
   return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,pu,pv,ans=0,h;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&h);
        node[i]=h;
    }
    for(i=0;i<m;i++)
        scanf("%d %d",&a[i].u,&a[i].v),a[i].w=node[a[i].u]+node[a[i].v];
    for(i=1;i<=n;i++) p[i]=i;
    sort(a,a+m);
    for(i=0;i<m;i++){
        pu=fin(a[i].u),pv=fin(a[i].v);
        if(pu!=pv){
            ans+=a[i].w;p[pu]=pv;
        }
    }
    printf("%d\n",ans);

    return 0;
}
