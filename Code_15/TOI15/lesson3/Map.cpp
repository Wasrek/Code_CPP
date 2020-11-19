/*
    TASK:Map
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[550][550],mii=1e9,mij=1e9,mai=0,maj=0,l[40010],u[40010],rl[40010],ru[40010];
void play(int i,int j,int x){
    mii=min(i,mii);
    mij=min(j,mij);
    mai=max(i,mai);
    maj=max(j,maj);
    if(l[x]!=-1){
        if(a[i][j+1]==-1){
        a[i][j+1]=l[x];
        play(i,j+1,l[x]);
        }
    }
    if(u[x]!=-1){
        if(a[i+1][j]==-1){
        a[i+1][j]=u[x];
        play(i+1,j,u[x]);
        }
    }
    if(rl[x]!=-1){
        if(a[i][j-1]==-1){
        a[i][j-1]=rl[x];
        play(i,j-1,rl[x]);
        }
    }
    if(ru[x]!=-1){
        if(a[i-1][j]==-1){
        a[i-1][j]=ru[x];
        play(i-1,j,ru[x]);
        }
    }
}
int main(){
    int i,n,m,x,y,j,f;
    char w;
    scanf("%d %d",&n,&m);
    memset(l,-1,sizeof l);
    memset(u,-1,sizeof u);
    memset(rl,-1,sizeof rl);
    memset(ru,-1,sizeof ru);
    memset(a,-1,sizeof a);
    for(i=1;i<m*n;i++){
        scanf("%d %c %d",&x,&w,&y);
        if(w=='L'){
            l[x]=y;
            rl[y]=x;
        }else
        if(w=='U'){
            u[x]=y;
            ru[y]=x;
        }
    }
    a[n][m]=x;
    play(n,m,x);
    for(i=mii;i<=mai;i++){
        for(j=mij;j<=maj;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
