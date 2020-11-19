/*
    TASK:Robot TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j,w;
    bool operator<(const A&o)const {
        return w>o.w;
    }
};
priority_queue< A > h;
long long dis[2020][2020],di[]={0,0,1,-1},dj[]={-1,1,0,0};
char a[2020][2020],st[2020];
int main(){
    long long n,m,cou=0,ans=0,i,j,k,all=0,w,ii,jj;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",st+1);
        for(j=1;j<=m;j++){
            a[i][j]=st[j];
            dis[i][j]=1<<30;
            if(a[i][j]=='X'){
                dis[i][j]=0;
                h.push({i,j,0});
            }
            if(a[i][j]=='A')all++;
        }
    }
    while(!h.empty()){
        i=h.top().i;
        j=h.top().j;
        w=h.top().w;
        h.pop();
        if(a[i][j]=='A'){
            cou++;
            ans+=w;
            a[i][j]='E';
        }
        if(cou==all){
            printf("%lld %lld\n",cou,ans*2);
            return 0;
        }
        for(k=0;k<4;k++){
            ii=i+di[k];
            jj=j+dj[k];
            if(a[ii][jj]=='W')continue;
            if(ii<1 || ii>n || jj<1 || jj>m)continue;
            if(dis[ii][jj]<=w+1)continue;
            dis[ii][jj]=w+1;
            h.push({ii,jj,dis[ii][jj]});
        }
    }
    printf("%lld %lld\n",cou,ans*2);
    return 0;
}
