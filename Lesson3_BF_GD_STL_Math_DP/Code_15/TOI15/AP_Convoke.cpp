/*
    TASK:AP_Convoke
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct V{
    long long u,w;
};
struct A{
    long long u,w,fri;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
long long f[20],dis[220][220],mark[220],ans[220][1<<16];
vector<V> g[220];
priority_queue< A >h;
map<long long,long long> mp;
int main(){
    long long n,m,i,a,b,w,k,tu,tw,tf,ch=0,s,j;
    scanf("%lld %lld %lld",&n,&m,&k);
    mark[1]=1;
    mark[n]=1;
    for(i=1;i<=k;i++){
        scanf("%lld",&f[i]);
        mark[f[i]]=1;
        mp[f[i]]=i;
    }
    f[k+1]=n;
    f[0]=1;
    mp[n]=k+1;
    //printf("c");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j)dis[i][j]=1e18;
        }
    }
    while(m--){
        scanf("%lld %lld %lld",&a,&b,&w);
        dis[a][b]=dis[b][a]=w;
    }
    //printf("c");
    for(i=1;i<=n;i++){
        for(j=1;j<=(1<<(k+2));j++){
            ans[i][j]=1e18;
        }
    }
    for(s=1;s<=n;s++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][s]+dis[s][j]);
            }
        }
    }
    //printf("c");
    ans[0][1]=0;
    h.push({1,0,0});
    while(!h.empty()){
        tu=h.top().u;
        tw=h.top().w;
        tf=h.top().fri;
        h.pop();
        //if(tu==n)continue;
        for(i=0;i<=k+1;i++){
            if(i!=0 && i!=k+1){
            if((tw+dis[tu][f[i]])<(ans[f[i]][(tf|(1<<(i-1)))])){
            ans[f[i]][(tf|(1<<(i-1)))]=tw+dis[tu][f[i]];
            h.push({f[i],tw+dis[tu][f[i]],(tf|(1<<(i-1)))});
            }
            }else{
                if((tw+dis[tu][f[i]])<(ans[f[i]][tf])){
            ans[f[i]][tf]=tw+dis[tu][f[i]];
            h.push({f[i],tw+dis[tu][f[i]],tf});
            }
            }
        }
    }
    //printf("c");
    printf("%lld\n",ans[n][(1<<k)-1]);
    return 0;
}
/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/
