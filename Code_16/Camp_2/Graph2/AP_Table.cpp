/*
    TASK:AP_Table
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long dis[50][50],di[]={-1,1,0,0},dj[]={0,0,1,-1};
char a[50][50];
struct A{
    long long i,j,w;
    bool operator < (const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > h;
int main()
{
    long long q,n,x,y,ma=0,ii,jj,i,j,k,w,ni,nj,c;;
    scanf("%lld",&q);
    while(q--){
        ma=0;
        scanf("%lld %lld %lld",&n,&x,&y);
        for(i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(ii=1;ii<=n;ii++){
                    for(jj=1;jj<=n;jj++){
                        dis[ii][jj]=1<<30;
                    }
                }
                dis[i][j]=0;
                h.push({i,j,0});
                while(!h.empty()){
                    ii=h.top().i;
                    jj=h.top().j;
                    w=h.top().w;
                    h.pop();
                    for(k=0;k<4;k++){
                        ni=ii+di[k];
                        nj=jj+dj[k];
                        if(ni<1 || ni>n || nj<1 || nj>n) continue;
                        if(a[ni][nj]==a[ii][jj]) c=x;
                        else c=y;
                        if(dis[ni][nj]<=w+c) continue;
                        dis[ni][nj]=w+c;
                        h.push({ni,nj,w+c});
                    }
                }
                for(ii=1;ii<=n;ii++){
                    for(jj=1;jj<=n;jj++){
                        ma=max(ma,dis[ii][jj]);
                    }
                }
            }
        }
        // printf("Hi\n");
        printf("%lld\n",ma);
    }
    return 0;
}
/*
1
3 1 2
AAA
ABA
AAB
*/