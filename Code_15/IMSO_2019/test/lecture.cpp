#include<bits/stdc++.h>
using namespace std;
long long t[1000010],r[1000010],dis[310][310],len[1000010],qs[1000010];
int main(){
    long long c,n,m;
    scanf("%lld %lld %lld",&c,&n,&m);
    for(int i=1;i<=c;i++){
        scanf("%lld",&r[i]);
    }
    for(int i=1;i<=c;i++){
        scanf("%lld",&t[i]);
        qs[i]=qs[i-1]+t[i];
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    long long a,b,w;
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a,&b,&w);
        dis[a][b]=dis[b][a]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=c;i++){
        len[i]=dis[r[i-1]][r[i]];
    }
    long long ll=1,rr=qs[c]*2;
    long long lf,ch;
    while(ll<rr){
        long long mid=(ll+rr+1)>>1;
        lf=t[1];
        ch=1;
        printf("%lld\n",mid);
        for(int i=2;i<=c;i++){
            if(r[i]==r[i-1]){
                lf+=t[i];
                continue;
            }
            if(len[i]*mid > lf+t[i]){
                ch=0;
                break;
            }
            lf=min(lf+t[i]-(len[i]*mid),t[i]-1);
        }
        if(!ch)rr=mid-1;
        else ll=mid;
    }
    printf("%lld\n",ll);
    return 0;
}
