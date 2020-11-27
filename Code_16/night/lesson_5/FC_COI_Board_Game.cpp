/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[550][550];
long long ma[550][550][1<<3],di[]={1,-1,0,0},dj[]={0,0,1,-1};
struct A{
    long long i,j,w,ma;
};
queue< A > q;
int main()
{
    long long n,m,si,sj,ei,ej,ti,tj,ni,nj,tw,tma;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++){
            if(a[i][j]=='S') si=i,sj=j;
            if(a[i][j]=='E') ei=i,ej=j;
            for(int k=0;k<=1<<3;k++) ma[i][j][k]=1<<30;
        }
    }
    // printf("%d %d %d %d\n",si,sj,ei,ej);
    ma[si][sj][0]=0;
    q.push({si,sj,0,0});
    while(!q.empty()){
        ti=q.front().i;
        tj=q.front().j;
        tw=q.front().w;
        tma=q.front().ma;
        q.pop();
        if(ti==ei && tj==ej){
            printf("%lld\n",tw);
            return 0;
        }
        // printf("%lld %lld %lld %lld\n",ti,tj,tw,tma);
        for(int k=0;k<4;k++){
            ni=ti+di[k];
            nj=tj+dj[k];
            if(ni<1 || ni>n || nj<1 || nj>m) continue;
            if(a[ni][nj]=='#') continue;
            if(a[ni][nj]=='j'){
                if(ma[ni][nj][tma | 1<<0] <=tw+1) continue;
                ma[ni][nj][tma | 1<<0]=tw+1;
                q.push({ni,nj,tw+1,tma | 1<<0});
            }else if(a[ni][nj]=='b'){
                if(ma[ni][nj][tma | 1<<1] <=tw+1) continue;
                ma[ni][nj][tma | 1<<1]=tw+1;
                q.push({ni,nj,tw+1,tma | 1<<1});
            }else if(a[ni][nj]=='p'){
                if(ma[ni][nj][tma | 1<<2] <=tw+1) continue;
                ma[ni][nj][tma | 1<<2]=tw+1;
                q.push({ni,nj,tw+1,tma | 1<<2});
            }else{
                if(!(1<<0 & tma) && a[ni][nj]=='J') continue;
                if(!(1<<1 & tma) && a[ni][nj]=='B') continue;
                if(!(1<<2 & tma) && a[ni][nj]=='P') continue;
                // printf("%lld\n",ma[ni][nj][tma]);
                if(ma[ni][nj][tma]<=tw+1) continue;
                // printf("go\n");
                ma[ni][nj][tma]=tw+1;
                q.push({ni,nj,tw+1,tma});
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*
2 5
S.J.b
.jB.E
*/