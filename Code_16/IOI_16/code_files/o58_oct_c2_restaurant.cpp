/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int cnt[330],dis[330][330],mark[330][330];
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&dis[i][j]);
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(mark[i][j] || k==i || k==j) continue;
                if(dis[i][j]==dis[i][k]+dis[k][j]){
                    // printf("%d %d %d\n",i,j,k);
                    mark[i][j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(!mark[i][j]) cnt[i]++,cnt[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        // printf("-%d ",cnt[i]);
        if(cnt[i]>2){
            (q==1) ? printf("%d\n",i) : printf("%d\n%d\n",i,cnt[i]);
            return 0;
        }
    }
    return 0;
}