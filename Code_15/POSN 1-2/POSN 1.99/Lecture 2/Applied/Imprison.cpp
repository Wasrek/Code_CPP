/*
    TASK:Imprison
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int mark[7600][7600],cou[15],x[7600],y[7600];
int main(){
int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int i,r,c;
    for(i=1;i<=p;i++){
        scanf("%d %d",&r,&c);
        x[i]=r;
        y[i]=c;
    }
    int Min=1e9,k,no,u,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=1;k<=p;k++){
                no=(abs(x[k]-i)+abs(y[k]-j));
                if(Min>no)Min=no,u=k;
            }
            cou[u]++;
            Min=1e9;
        }
    }
    for(i=1;i<=p;i++){
        printf("%d\n",cou[i]);
    }
    return 0;
}
/*
int mark[7600][7600],di[]={0,0,1,-1},dj[]={-1,1,0,0},;
struct A{
    int r,c,l;
};
queue< A > q;
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int i,x,y;
    for(i=1;i<=p;i++){
        scanf("%d %d",&x,&y);
        mark[x][y]=i;
        q.push({x,y,i});
        cou[i]++;
    }
    int k,nexti,nextj,j,w;
    while(!q.empty()){
        i=q.front().r,j=q.front().c,w=q.front().l;
        q.pop();
        for(k=0;k<4;k++){
            nexti=i+di[k],nextj=j+dj[k];
            if(nexti<1 || nextj<1 || nexti>n || nextj>m)continue;
            if(mark[nexti][nextj]!=0)continue;
            mark[nexti][nextj]=w;
            cou[w]++;
            q.push({nexti,nextj,w});
        }
    }
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ",mark[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=p;i++){
        printf("%d\n",cou[i]);
    }
    return 0;
}*/
