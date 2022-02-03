/*
    TASK:TOI4 Cromartie School
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
char a[100][100];
int qs[100][100],mark[100][100],di[]={1,-1,0,0},dj[]={0,0,1,-1},n,m,p[4500];
vector< A > v;
void play(int na,int i,int j){
    mark[i][j]=na;
    int ii,jj;
    for(int k=0;k<4;k++){
        ii=i+di[k];
        jj=j+dj[k];
        if(ii<1 || ii>n || jj<1 || jj>m) continue;
        if(a[ii][jj]=='P' && !mark[ii][jj]){
            play(na,ii,jj);
        }
    }
    return ;
}
int main()
{
    int ma=0;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]!='T') qs[i][j]=min(min(qs[i-1][j],qs[i][j-1]),qs[i-1][j-1])+1;
            // printf("%d",qs[i][j]);
            if(qs[i][j]>ma){
                ma=qs[i][j];
                v.clear();
                v.push_back({i,j});
            }else if(qs[i][j]==ma){
                v.push_back({i,j});
            }
        }
    }
    int now=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='P' && !mark[i][j]){
                ++now;
                play(now,i,j);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d",mark[i][j]);
    //     }
    //     printf("\n");
    // }
    now=0;
    int cnt=0,mi=1e9;
    for(auto x:v){
        cnt=0;
        for(int i=x.i-ma+1;i<=x.i;i++){
            for(int j=x.j-ma+1;j<=x.j;j++){
                if(mark[i][j] && !p[mark[i][j]]){
                    cnt++;
                    // printf("%d %d %d\n",now,i,j);
                    p[mark[i][j]]=1;
                }
            }
        }
        mi=min(cnt,mi);
        memset(p,0,sizeof p);
    }
    if(mi==1e9)mi=0;
    printf("%d %d",ma*ma,mi);
    return 0;
}