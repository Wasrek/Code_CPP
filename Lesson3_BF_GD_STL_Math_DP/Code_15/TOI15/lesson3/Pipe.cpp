/*
    TASK:Pipe
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][310],cou=0,ans[1000],c,n,m;
void dfs(int i,int j,int st){
    if(i<1 || i>n || j<1 || j>m)return ;
    c++;
    if(a[i][j]==11){
        a[i][j]=0;
        if(st==0){
            dfs(i,j-1,2);
        }else
        if(st==3){
            dfs(i-1,j,1);
        }
    }else
    if(a[i][j]==12){
        a[i][j]=0;
        if(st==0){
            dfs(i,j+1,3);
        }else
        if(st==2){
            dfs(i-1,j,1);
        }
    }else
    if(a[i][j]==13){
        a[i][j]=0;
        if(st==1){
            dfs(i,j-1,2);
        }else
        if(st==3){
            dfs(i+1,j,0);
        }
    }else
    if(a[i][j]==14){
        a[i][j]=0;
        if(st==1){
            dfs(i,j+1,3);
        }else
        if(st==2){
            dfs(i+1,j,0);
        }
    }else
    if(a[i][j]==21){
        a[i][j]=0;
        if(st==0){
            dfs(i+1,j,0);
        }else
        if(st==1){
            dfs(i-1,j,1);
        }
    }else
    if(a[i][j]==22){
        a[i][j]=0;
        if(st==3){
            dfs(i,j+1,3);
        }else
        if(st==2){
            dfs(i,j-1,2);
        }
    }else
    if(a[i][j]==31){
        if(st==0 || st==1){
            a[i][j]=22;
            if(st==1)dfs(i-1,j,1);
            else if(st==0)dfs(i+1,j,0);
        }else
        if(st==2 || st==3){
            a[i][j]=21;
            if(st==2)dfs(i,j-1,2);
            else if(st==3)dfs(i,j+1,3);
        }
    }
}
int main(){
    int i,j,id=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    /*
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    for(i=1;i<=m;i++){
        if(a[1][i]==11 || a[1][i]==12 || a[1][i]==21 || a[1][i]==31)
        c=0,dfs(1,i,0),cou++,ans[id++]=c;//printf("c");
    }
    for(i=1;i<=m;i++){
        if(a[n][i]==13 || a[n][i]==14 || a[n][i]==21 || a[n][i]==31)
        c=0,dfs(n,i,1),cou++,ans[id++]=c;//printf("c");
    }
    for(i=1;i<=n;i++){
        if(a[i][1]==11 || a[i][1]==13 || a[i][1]==22 || a[i][1]==31)
        c=0,dfs(i,1,3),cou++,ans[id++]=c;//printf("c");
    }
    for(i=1;i<=n;i++){
        if(a[i][m]==12 || a[i][m]==14 || a[i][m]==22 || a[i][m]==31)
        c=0,dfs(i,m,2),cou++,ans[id++]=c;//printf("c");
    }
    printf("%d\n",cou);
    sort(ans,ans+id);
    for(i=0;i<id;i++)printf("%d ",ans[i]);
    printf("\n");
}
