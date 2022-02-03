/*
    TASK:Transfuse
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[10][10];
int dir[4]={0,0,1,-1},dic[4]={1,-1,0,0},mark[10][10];
int n,m,cnt,ma=-1,mi=1e9;
void play(int i,int j,int step){
    if(i==n-1 && j==m-1){
        cnt++;
        ma =max(ma,step);
        mi =min(mi,step);
        return ;
    }
    for(int k=0;k<4;k++){
        int ii=i+dir[k],jj=j+dic[k];
        if(ii<0 || ii>=n || jj<0 || jj>=m)continue;
        if(mark[ii][jj] ||  a[ii][jj]=='#') continue;
        mark[ii][jj]=1;
        play(ii,jj,step+1);
        mark[ii][jj]=0;
    }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf(" %s",a[i]);
    }
    mark[0][0]=1;
    play(0,0,0);
    printf("%d %d %d",cnt,ma+1,mi+1);
    return 0;
}
