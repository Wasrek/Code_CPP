/*
    TASK:BUU Climbing
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
priority_queue< A > he;
char a[110][110];
int h[110][110],dis[110][110],di[]={1,1,1,0,0,-1,-1,-1},dj[]={-1,0,1,-1,1,-1,0,1};
int main()
{
    int q,n,m,si,sj,ei,ej,ma=0,w;
    scanf("%d",&q);
    while(q--){
        ma=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
            for(int j=1;j<=m;j++){
                dis[i][j]=2e9;
                if(a[i][j]=='#'){continue;}
                if(a[i][j]-'0'>ma){
                    ei=i;
                    ej=j;
                    ma=a[i][j]-'0';
                }
                h[i][j]=a[i][j]-'0';
            }
        }
        scanf("%d %d",&si,&sj);
        si++;
        sj++;
        // printf("%d %d\n",ei,ej);
        dis[si][sj]=0;
        he.push({si,sj,0});
        int i,j,ii,jj,len,ch=0;
        while(!he.empty()){
            i=he.top().i;
            j=he.top().j;
            w=he.top().w;
            he.pop();
            if(i==ei && j==ej){
                printf("%d\n",w);
                ch=1;
                break;
            }
            for(int k=0;k<8;k++){
                ii=i+di[k];
                jj=j+dj[k];
                if(ii<1 || ii>n || jj<1 || jj>m)continue;
                if(a[ii][jj]=='#')continue;
                len=abs(h[i][j]-h[ii][jj])+1;
                len*=len;
                if(dis[ii][jj]<=len+w) continue;
                dis[ii][jj]=len+w;
                he.push({ii,jj,len+w});
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         printf("%d ",dis[i][j]);
        //     }
        //     printf("\n");
        // }
        if(ch){
            while(!he.empty()) he.pop();
        }else printf("NO\n");
    }
    return 0;
}