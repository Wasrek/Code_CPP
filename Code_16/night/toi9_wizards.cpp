#include<bits/stdc++.h>
using namespace std;
#define hashsize 5000011
int hashtb[hashsize],k[2][hashsize];
int x[4][1510],y[4][1510];
long long now; 
int main()
{
    int wa,wb,n,sx,sy,ans;
    scanf("%d %d %d",&wa,&wb,&n);
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            scanf("%d %d",&x[i][j],&y[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sx=x[0][i]+x[1][j];
            sy=y[0][i]+y[1][j];
            now=(((sx+(3*sy)%hashsize)%hashsize)+hashsize)%hashsize;
            while(hashtb[now]){
                now++;
                now%=hashsize;
            }
            hashtb[now]=(1500*i)+j+1;
            k[0][now]=sx;
            k[1][now]=sy;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sx=wa-(x[2][i]+x[3][j]);
            sy=wb-(y[2][i]+y[3][j]);
            now=(((sx+(3*sy)%hashsize)%hashsize)+hashsize)%hashsize;
            while(hashtb[now]){
                if(k[0][now]==sx && k[1][now]==sy){
                    ans=hashtb[now]-1;
                    printf("%d %d\n",x[0][ans/1500],y[0][ans/1500]);
                    printf("%d %d\n",x[1][ans%1500],y[1][ans%1500]);
                    printf("%d %d\n",x[2][i],y[2][i]);
                    printf("%d %d\n",x[3][j],y[3][j]);
                    return 0;
                }
                now++;
                now%=hashsize;
            }
        }
    }
    return 0;
}