/*
    TASK: Slikar
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
   int i,j,arai;// 1=water 2=human
};
queue< A > qu;
char a[100][100];
int dis[100][100],di[4]={1,-1,0,0},dj[4]{0,0,1,-1};
int main()
{
    int r,c,i,h,sti,stj,eni,enj,j,nexti,nextj,k,ch=1,arai;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='S')
                sti=i,stj=j;
            if(a[i][j]=='D')
                eni=i,enj=j;
            if(a[i][j]=='*')
            qu.push({i,j,1});
        }
    }
    memset(dis,-1,sizeof dis);
    qu.push({sti,stj,2});
    dis[sti][stj]=0;
    while(!qu.empty()){
        i=qu.front().i,j=qu.front().j,arai=qu.front().arai;
        qu.pop();
        if(i==eni && j==enj && arai==2){
            ch=0; break;
        }
        for(k=0;k<4;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<0||nextj<0||nexti>=r||nextj>=c)continue;
            if(a[nexti][nextj]=='X'||a[nexti][nextj]=='*')continue;
            if(dis[nexti][nextj]!=-1)continue;
            if(arai==1&&a[nexti][nextj]=='D') continue;
            dis[nexti][nextj]=dis[i][j]+1;
            qu.push({nexti,nextj,arai});
        }
    }
    if(ch) printf("KAKTUS\n");
    else printf("%d\n",dis[eni][enj]);
    return 0;
}
