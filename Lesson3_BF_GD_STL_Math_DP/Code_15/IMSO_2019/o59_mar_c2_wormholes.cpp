/*
    TASK:wormhole
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long disf(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
struct A{
    long long x,y;
};
A a[20000];
long long dis[100][100];
int main()
{
    long long n,q,x1,y1,x2,y2;
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n*2;j++){
            dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&a[i*2-1].x,&a[i*2-1].y,&a[i*2].x,&a[i*2].y);
        dis[i*2-1][i*2]=0;
        dis[i*2][i*2-1]=0;
    }
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n*2;j++){
            if(dis[i][j]!=0){
                dis[i][j]=disf(a[i].x,a[i].y,a[j].x,a[j].y);
            }
        }
    }
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n*2;j++){
            for(int k=1;k<=n*2;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    long long mi,now;
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        mi=disf(x1,y1,x2,y2);
        for(int i=1;i<=n*2;i++){
            for(int j=1;j<=n*2;j++){
                now=disf(x1,y1,a[i].x,a[i].y)+disf(x2,y2,a[j].x,a[j].y)+dis[i][j];
                mi=min(mi,now);
            }
        }
        printf("%lld\n",mi);
    }
    return 0;
}