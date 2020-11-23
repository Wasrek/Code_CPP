/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct H{
    long long i,w,num;
    bool operator <(const H & o) const{
        return w>o.w;
    }
};
vector< long long > g;
priority_queue< H > h;
long long dis[210][(1<<20)],pa[210][210];
unordered_map< int,int> mp;
int main()
{
    long long n,m,k,s,a,b,w,cnt=0,num;
    scanf("%lld %lld %lld",&n,&m,&k);
    g.push_back(1);
    for(int i=1;i<=k;i++){
        scanf("%lld",&num);
        mp[num]=++cnt;
        g.push_back(num);
    }
    g.push_back(n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=(1<<(k));j++){
            dis[i][j]=1<<30;
        }
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            pa[i][j]=pa[j][i]=1<<30;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a,&b,&w);
        pa[a][b]=pa[b][a]=min(pa[a][b],w);
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                pa[i][j]=min(pa[i][j],pa[i][l]+pa[l][j]);
            }
        }
    }
    dis[1][0]=0;
    h.push({1,0,0});
    while(!h.empty()){
        a=h.top().i;
        w=h.top().w;
        num=h.top().num;
        h.pop();
        // printf("%lld %lld %lld\n",a,w,num);
        if(a==n && num==(1<<(k))-1){
            printf("%lld\n",w);
            return 0;
        }
        for(auto x: g){
            if(mp[x]){
                // printf("- %lld\n",x);
                if(w+pa[a][x]>=dis[x][num | (1<<(mp[x]-1))]) continue;
                dis[x][num | (1<<(mp[x]-1))]=w+pa[a][x];
                h.push({x,dis[x][num | (1<<(mp[x]-1))],num | (1<<(mp[x]-1))});
            }else{
                // printf("* %lld\n",x);
                if(w+pa[a][x]>=dis[x][num]) continue;
                dis[x][num]=w+pa[a][x];
                h.push({x,dis[x][num],num});
            }
        }
    }
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