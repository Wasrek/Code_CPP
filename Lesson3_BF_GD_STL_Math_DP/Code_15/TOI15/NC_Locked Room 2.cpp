/*
    TASK:NC_Locked Room 2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=105;
struct A{
    int u,w,b;
    bool operator<(const A &o)const{
        return w>o.w;
    }
};
priority_queue< A > dijk;
vector< A >g[35];
queue<pair<int,int>>bfs;
char str[N][N];
int dp[35][1<<16];
int dist[N][N],door[N][N],key[N][N];
int di[]={1,-1,0,0},dj[]={0,0,1,-1};
int main(){
    int i,j,k,l,a,b,c,d,n,ii,jj;
    int sti,stj,eni,enj;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf(" %s",str[i]+1);
    memset(door,-1,sizeof door);
    memset(key,-1,sizeof key);
    scanf("%d %d %d %d %d",&sti,&stj,&eni,&enj,&k);
    for(i=0;i<k;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        key[a][b]=door[c][d]=i;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            int now;
            if(key[i][j]!=-1) now=key[i][j];
            else if(door[i][j]!=-1) now=door[i][j]+k;
            else if(sti==i && stj==j)now=2*k;
            else if(eni==i && enj==j)now=2*k+1;
            else continue;
            memset(dist,-1,sizeof dist);
            dist[i][j]=0;
            bfs.push({i,j});
            while(!bfs.empty()){
                ii=bfs.front().x,jj=bfs.front().y;
                bfs.pop();
                for(l=0;l<4;l++){
                    int ni=ii+di[l],nj=jj+dj[l];
                    if(ni<1 || nj<1 || ni>n || nj>n || str[ni][nj]=='#' || dist[ni][nj]!=-1)continue;
                    dist[ni][nj]=dist[ii][jj]+1;
                    if(key[ni][nj]!=-1) g[now].push_back({key[ni][nj],dist[ni][nj],1<<key[ni][nj]});
                    if(door[ni][nj]!=-1) g[now].push_back({door[ni][nj]+k,dist[ni][nj],0});
                    if(sti==ni && stj==nj) g[now].push_back({2*k,dist[ni][nj],0});
                    if(eni==ni && enj==nj) g[now].push_back({2*k+1,dist[ni][nj],0});
                    if(door[ni][nj]==-1){
                        bfs.push({ni,nj});
                    }
                }
            }
        }
    }
    for(i=0;i<=2*k+1;i++){
        for(j=0;j<(1<<k);j++) dp[i][j]=1<<30;
    }
    dp[2*k][0]=0;
    dijk.push({2*k,0,0});
    while(!dijk.empty()){
        int u=dijk.top().u,w=dijk.top().w,bit=dijk.top().b;
        dijk.pop();
        for(A e:g[u]){
            if(e.u>=k && e.u<2*k){
                if(bit & (1<<(e.u-k))){
                    if(dp[e.u][bit]>w+e.w){
                       dp[e.u][bit]= w+e.w;
                       dijk.push({e.u,dp[e.u][bit],bit});
                    }
                }
            }else{
                if(dp[e.u][bit|e.b]>w+e.w){
                    dp[e.u][bit|e.b]=w+e.w;
                    dijk.push({e.u,dp[e.u][bit|e.b],bit|e.b});
                }
            }
        }
    }
    int ans=1<<30;
    for(i=0;i<(1<<k);i++){
        ans=min(ans,dp[2*k+1][i]);
    }
    if(ans==1<<30) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
