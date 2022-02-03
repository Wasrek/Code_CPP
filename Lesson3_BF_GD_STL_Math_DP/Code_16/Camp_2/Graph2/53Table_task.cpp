/*
    TASK:53Table_task
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j,w,k;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
long long t[110][110],dis[2][110][110];
long long di[]={1,-1,0,0},dj[]={0,0,1,-1};
int main()
{
    long long n,m,si,sj,ei,ej;
    scanf("%lld %lld %lld %lld %lld %lld",&n,&m,&si,&sj,&ei,&ej);
    long long hr,mi;
    scanf("%lld:%lld",&hr,&mi);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            scanf("%lld",&t[i][j]);
            dis[0][i][j]=dis[1][i][j]=1<<30;
        }
    }
    dis[0][si][sj]=t[si][sj];
    if(t[si][sj]>=0){
    h.push({si,sj,t[si][sj],0});
    }else{
        h.push({si,sj,t[si][sj],1});
        h.push({si,sj,0,0});
    }
    long long i,j,w,k,ni,nj,c;
    while(!h.empty()){
        i=h.top().i;
        j=h.top().j;
        w=h.top().w;
        k=h.top().k;
        h.pop();
        // printf("%d %d %d %d\n",i,j,w,k);
        for(long long l=0;l<4;l++){
            ni=i+di[l];
            nj=j+dj[l];
            if(ni<1 || ni>n || nj<1 || nj>m) continue;
            c=max(t[ni][nj],0ll);
            if(dis[k][ni][nj]>w+c){
               dis[k][ni][nj]=w+c;
               h.push({ni,nj,w+c,k}); 
            }
            if(t[ni][nj]<0 && !k && dis[1][ni][nj]>w+t[ni][nj]){
                dis[1][ni][nj]=w+t[ni][nj];
                h.push({ni,nj,w+t[ni][nj],1});
            }
        }
    }
    long long now,ans=min(dis[1][ei][ej],dis[0][ei][ej]);
    // printf("%lld\n",ans);
    int ch=0;
    if(ans<0) ch=1,ans*=-1;
    ans%=720;
    if(ch)ans*=-1;
    now=(hr*60ll)+mi;
    now+=ans;
    now+=720ll;
    now%=720ll;
    hr=now/60ll;
    mi=now%60ll;
    if(hr<10ll){
        printf("0%lld:",hr);
    }else printf("%lld:",hr);
    if(mi<10ll){
        printf("0%lld",mi);
    }else printf("%lld",mi);
    return 0;
}