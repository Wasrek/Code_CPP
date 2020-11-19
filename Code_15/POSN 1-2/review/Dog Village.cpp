/*
    TASK:Dog Village
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],dis[1010][1010],di[]={0,0,1,-1},dj[]={-1,1,0,0};
typedef pair<int,int> A;
queue<A> q;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    memset(dis,-1,sizeof dis);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)q.push({i,j}),dis[i][j]=0;
        }
    }
    int k,nexti,nextj;
    while(!q.empty()){
        i=q.front().first,j=q.front().second;
        q.pop();
        for(k=0;k<4;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<0 || nextj<0 || nexti>=n || nextj>=m)continue;
            if(dis[nexti][nextj]!=-1)continue;
            if(dis[i][j]+1>=a[nexti][nextj])continue;
            dis[nexti][nextj]=dis[i][j]+1;
            q.push({nexti,nextj});
        }
    }
    int cou=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(dis[i][j]==-1)cou++;
        }
    }
    printf("%d\n",cou);
}
