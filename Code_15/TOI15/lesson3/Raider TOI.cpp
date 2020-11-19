/*
    TASK:Raider TOI
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,dis;
};
queue< A > q;
int a[100][150],mark[100][150],di[]={-1,-1,0,0,1,1},dj[]={0,1,-1,1,0,1},ki[]={-1,-1,0,0,1,1},kj[]={-1,0,-1,1,-1,0};
int main(){
    int n,m,i,j,ii,jj,d,iii,jjj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(a[n/2][1]==1)
    q.push({(n/2),1,1});
    //printf("%d",a[n/2][1]);
    if(a[n/2+1][1]==1)
    q.push({(n/2)+1,1,1});
    if(a[n/2+2][1]==1)
    q.push({(n/2)+2,1,1});
    //memset(mark,-1,sizeof mark);
    //mark[n/2][1]=1;
    //mark[n/2+1][1]=1;
    //mark[n/2+2][1]=1;
    while(!q.empty()){
        ii=q.front().i;
        jj=q.front().j;
        d=q.front().dis;
        q.pop();
        //printf("%d %d %d\n",ii,jj,d);
        if(ii==(n+1)/2 && jj==m){
            printf("%d\n",d);
            return 0;
        }
        if(ii%2==0){
        for(j=0;j<6;j++){
            iii=ii+ki[j];
            jjj=jj+kj[j];
            if(iii<1 || iii>n || jjj<1 || jjj>m)continue;
            if(a[iii][jjj]==0)continue;
            if((d+1)%a[iii][jjj] || (d+1)==mark[iii][jjj])continue;
            mark[iii][jjj]=d+1;
            q.push({iii,jjj,d+1});
        }
        }
        else{
        for(j=0;j<6;j++){
            iii=ii+di[j];
            jjj=jj+dj[j];
            if(iii<1 || iii>n || jjj<1 || jjj>m)continue;
            if(a[iii][jjj]==0)continue;
            if((d+1)%a[iii][jjj] || (d+1)==mark[iii][jjj]){continue;}
            mark[iii][jjj]=d+1;
            q.push({iii,jjj,d+1});
        }
        }
    }
}
