/*
    TASK:FC_Jewel
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,i;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
A a[500010];
long long w[500010],p[500010],mark[500010];
long long fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    long long n,k,i,ans=0,mi,pi,ii,iw;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i].w);
        a[i].i=i;
        w[i]=a[i].w;
        p[i]=i;
    }
    p[0]=0;
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        ii=a[i].i;
        mi=fin(ii-1);
        pi=fin(ii+1);
        iw=a[i].w;
        if(mark[ii+1] && mark[ii-1] && w[mi]+w[pi]+iw>k)continue;
        if(mark[ii+1] && mark[ii-1]){
            mark[ii]=1;
            p[ii]=p[mi]=pi;
            ans+=iw;
            w[fin(ii)]+=iw;
            continue;
        }
        if(mark[ii+1]){
            if(w[pi]+iw>k)continue;
            mark[ii]=1;
            p[ii]=pi;
            ans+=iw;
            w[fin(ii)]+=iw;
            continue;
        }
        if(mark[ii-1]){
            if(w[mi]+iw>k)continue;
            mark[ii]=1;
            p[ii]=mi;
            ans+=iw;
            w[fin(ii)]+=iw;
            continue;
        }
        mark[ii]=1;
        ans+=iw;
    }
//    for(i=1;i<=n;i++)printf("%d ",fin(i));
//    printf("\n");
//    for(i=1;i<=n;i++)printf("%d ",w[fin(i)]);
    printf("%lld\n",ans);
}
