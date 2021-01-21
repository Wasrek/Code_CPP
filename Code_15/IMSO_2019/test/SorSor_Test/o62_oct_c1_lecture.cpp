/*
    TASK:lecture
*/
#include<bits/stdc++.h>
using namespace std;
long long t[100010],r[100010],qs[100010],dis[310][310],len[100010];
int main()
{
    long long  c,n,m,a,b,w;
    scanf("%lld %lld %lld",&c,&n,&m);
    for(int i=1;i<=c;i++){
        scanf("%lld",&r[i]);
    }
    for(int i=1;i<=c;i++){
        scanf("%lld",&t[i]);
    }
    for(int i=1;i<=c;i++){
        qs[i]=t[i]+qs[i-1];
//        printf("%d ",qs[i]);
    }
//    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a,&b,&w);
        dis[a][b]=w;
        dis[b][a]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
//                printf("%d %d %d %d",i,j,k,dis[i][k]);
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
//    for(int i=1;i<=c;i++){
//        printf("%d ",qs[i]);
//    }
    for(int i=1;i<=c;i++){
        len[i]=dis[r[i-1]][r[i]];
        //printf("%d ",len[i]);
    }
//    printf("\n");
//    for(int i=1;i<=n;i++){
//        printf("%d ",len[i]);
//    }
//    printf("\n");
    long long  ll=1,rr=1e18;
    long long  ch,left;
    long long  mid=0,last=0;
//    printf("%d %d\n",ll,rr);
    while(ll<rr){
        mid=(ll+rr+1)>>1;
        ch=1;
        last=0;
        left=t[1];
        for(int i=2;i<=c;i++){
            if(r[i]==r[i-1]){
                last+=t[i];
                if(i==2)last=t[2]+t[1];
                continue;
            }
//            printf("%lld %lld %lld %lld %lld\n",mid,last,qs[i],len[i],left);
            if(len[i]*mid+last>qs[i] && len[i]*mid>left+t[i]){
                ch=0; break;
            }
            last+=len[i]*mid;
            last=max(last,qs[i-1]+1);
            left=qs[i]-last;
        }
        if(!ch)rr=mid-1;
        else ll=mid;
//        printf("%d %d\n",ll,rr);
    }
    printf("%lld\n",ll);
    return 0;
}
