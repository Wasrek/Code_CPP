/*
    TASK:Robot TOI13
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j,w;
};
char a[2020][2020];
long long dis[2020][2020];
long long di[]={0,0,1,-1},dj[]={1,-1,0,0};
queue< A > q;
int main()
{
    long long  n,m,total=0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(long long j=1;j<=m;j++){
            dis[i][j]=1<<30;    
            if(a[i][j]=='X'){
                q.push({i,j,0});
                dis[i][j]=0;
            }
            if(a[i][j]=='A')total++;
        }
    }
    long long ii,jj,i,j,w,get=0;;
    long long ans=0;
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        w=q.front().w;
        q.pop();
        if(a[i][j]=='A'){
            ans+=w*2;
            get++;
            if(get==total){
                printf("%lld %lld\n",get,ans);
                return 0;
            }
        }
        for(long long k=0;k<4;k++){
            ii=i+di[k];
            jj=j+dj[k];
            if(ii<1 || ii>n || jj<1 || jj>m) continue;
            if(a[ii][jj]=='W') continue;
            if(dis[ii][jj]<=w+1)continue;
            dis[ii][jj]=w+1;
            q.push({ii,jj,w+1});
        }
    }
    printf("%lld %lld\n",get,ans);
    return 0;
}