/*
    TASK:Walk Horse
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int dis[1010][1010],r,c,i,j,sti,stj,eni,enj,k,nexti,nextj;
int di[8]={-2,-1,-2,-1,+2,+1,+2,+1},dj[8]={-1,-2,+1,+2,-1,-2,+1,+2};
typedef pair<int,int> PII;
queue <PII> q;
int main()
{
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        scanf(" %c",&a[i][j]);
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    if(a[sti][stj]=='X'||a[eni][enj]=='X'){
        printf("-1\n"); return 0;
    }
    memset(dis,-1,sizeof dis);
    q.push({sti,stj});
    dis[sti][stj]=0;
    while(!q.empty()){
        i=q.front().first,j=q.front().second;
        q.pop();
        if(i==eni&&j==enj)
            break;
        for(k=0;k<8;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<1||nextj<1||nexti>r||nextj>c) continue;
            if(a[nexti][nextj]=='X') continue;
            if(dis[nexti][nextj]!=-1) continue;
            dis[nexti][nextj]=dis[i][j]+1;
            q.push({nexti,nextj});
        }
    }
    printf("%d\n",dis[eni][enj]);
    return 0;
}
