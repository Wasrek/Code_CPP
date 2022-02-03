/*
    TASK:Sink hill
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010],l[1010][1010],r[1010][1010],u[1010][1010],d[1010][1010];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&a[i][j]);
                l[i][j]=r[i][j]=u[i][j]=d[i][j]=1;
                if(a[i][j]>=a[i-1][j])
                u[i][j]+=u[i-1][j];
                if(a[i][j]>=a[i][j-1])
                l[i][j]+=l[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            l[i][m+1]=r[i][m+1]=u[i][m+1]=d[i][m+1]=0;
        }
        for(int j=1;j<=m;j++){
            l[n+1][j]=r[n+1][j]=u[n+1][j]=d[n+1][j]=0;
        }
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(a[i][j]>=a[i+1][j])
                d[i][j]+=d[i+1][j];
                if(a[i][j]>=a[i][j+1])
                r[i][j]+=r[i][j+1];
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         printf("%d ",d[i][j]);
        //     }
        //     printf("\n");
        // }
        long long ma=0,k=0,ii,jj;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                k=ma;
                ma=max(ma,u[i][j]+l[i][j]+r[i][j]+d[i][j]-(3));
                if(k!=ma) ii=i,jj=j;
            }
        }
        printf("%lld\n%lld %lld\n",ma,ii,jj);
    }
    return 0;
}