/*
    TASK:Nearest Walk
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1100][1100];
int dis[1100][1100],dir[4]={1,-1,0,0},dic[4]={0,0,1,-1};
typedef pair<int,int> PII;
queue< PII > qu;
int main()
{
    int q,r,c,i,j,sti,stj,eni,enj,nexti,nextj,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='A')
                    sti=i,stj=j;
                if(a[i][j]=='B')
                    eni=i,enj=j;
            }
        }
        memset(dis,-1,sizeof dis);
        qu.push({sti,stj});
        dis[sti][stj]=0;
        while(!qu.empty()){
            i=qu.front().first,j=qu.front().second;
            qu.pop();
            if(i==eni && j==enj)
                break;
            for(k=0;k<4;k++){
                nexti=i+dir[k],nextj=j+dic[k];
                if(nexti<0||nextj<0||nexti>=r||nextj>=c) continue;
                if(a[nexti][nextj]=='#') continue;
                if(dis[nexti][nextj]!=-1) continue;
                dis[nexti][nextj]=dis[i][j]+1;
                qu.push({nexti,nextj});
            }
        }
        printf("%d\n",dis[eni][enj]);
        while(!qu.empty())
            qu.pop();
    }
    return 0;
}

