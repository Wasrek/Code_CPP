/*
    TASK:RT_WakeUP
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
};
long long dis[15100];
A a[15100];
int p;
long long ppp(long long n){
    long long nn=1,l=p;
    while(l--){
        nn*=n;
    }
    return nn;
}
int main(){
    int n,s,i,j,tu,tv,tw;
    long long o;
    scanf("%d %d %d %lld",&n,&p,&s,&o);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    for(i=1;i<=n;i++){
        dis[i]=1ll<<60;
    }
    dis[s]=0;
    int k;
    long long ans=0,mi,w;
    o=o*(n-1);
    swap(a[1],a[s]);
    swap(dis[1],dis[s]);
    for(j=1;j<n;j++){
        mi=1e18;
        for(i=j+1;i<=n;i++){
            w=(ppp(abs(a[i].x-a[j].x))+ppp(abs(a[i].y-a[j].y)))*2;
            if(dis[i]>w)
            dis[i]=w;
            if(dis[i]<mi){
                    mi=dis[i],k=i;
            }
        }
        swap(a[j+1],a[k]);
        swap(dis[j+1],dis[k]);
    }
    for(i=1;i<=n;i++)ans+=dis[i]/*,printf("%lld\n",dis[i])*/;
    printf("%lld\n",ans+o);
}
/*
2
1
1
0
1 1
2 2


3
2
3
1
1 4
2 6
3 3
*/
