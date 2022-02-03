/*
    TASK:Connect
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
A a[1010];
double dis[1010][1010],mark[1010];
struct B{
    int u;
    double w;
    bool operator<(const B & o) const{
        return w>o.w;
    }
};
priority_queue< B > h;
int main()
{
    int n,w,k,l;
    double m;
    scanf("%d %d",&n,&w);
    scanf("%lf",&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        mark[i]=1<<30;
        for(int j=1;j<i;j++){
            dis[i][j]=sqrt((double)pow((double)(a[i].x-a[j].x),2)+(double)pow((double)(a[i].y-a[j].y),2));
            dis[j][i]=dis[i][j];
        }
    }
    for(int i=1;i<=w;i++){
        scanf("%d %d",&k,&l);
        dis[k][l]=0;
        dis[l][k]=0;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%.1lf ",dis[i][j]);
    //     }
    //     printf("\n");
    // }
    h.push({1,0});
    mark[1]=0;
    int u;
    double ww;
    while(!h.empty()){
        u=h.top().u;
        ww=h.top().w;
        h.pop();
        // printf("%d %.1lf\n",u,ww);
        if(u==n){
            printf("%d\n",(int)(ww*1000));
            return 0;
        }
        for(int i=1;i<=n;i++){
            // printf("%d\n",i);
            if(mark[i]<=ww+dis[u][i] || dis[u][i]>m) continue;
            // printf("%.1lf %.1lf\n",ww,dis[u][i]);
            mark[i]=ww+dis[u][i];
            h.push({i,mark[i]});
        }
    }
    printf("-1\n");
    return 0;
}