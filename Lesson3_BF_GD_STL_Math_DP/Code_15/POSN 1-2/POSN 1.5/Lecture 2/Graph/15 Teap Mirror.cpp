/*
    TASK:Teap mirror
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
typedef pair<int,int> PII;
queue< PII > bfs;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1},dis[110][110];
int main()
{
    int r,c,i,j,ch=1,sti,stj,eni,enj,ii,jj,k;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='M' && ch)
            sti=i,stj=j,ch=0;
            else if(a[i][j]=='M' && ch==0)
                eni=i,enj=j;
        }
    }
    memset(dis,-1,sizeof dis);
    dis[sti][stj]=0;
    bfs.push({sti,stj});
    while(!bfs.empty()){
        i=bfs.front().first,j=bfs.front().second; bfs.pop();
        if(i==eni && j==enj){
            printf("%d\n",dis[eni][enj]-1);
            return 0;
        }
        for(k=0;k<4;k++){
                ii=i,jj=j;
            while(1){
                ii+=di[k],jj+=dj[k];
                if(ii<0||ii>=r||jj<0||jj>=c) break;
                if(a[ii][jj]=='*') break;
                if(dis[ii][jj]!=-1) continue;
                dis[ii][jj]=dis[i][j]+1;
                bfs.push({ii,jj});
            }
        }
    }
    return 0;
}
