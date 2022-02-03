/*
    TASK:RT_Thanos
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;

};
int dis[3030][3030];
char a[3030][3030],s[3030];
queue< A > q;
int main(){
    int mi=1e9,i,j,n,m,ii,jj,k,mim=0,len;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",s+1);
        for(j=1;j<=m;j++){
            a[i][j]=s[j];
            dis[i][j]=1e9;
            if(a[i][j]=='X'){
            dis[i][j]=0;
            q.push({i,j});
            mim=max(mim,i);
            }
        }
    }
    //printf("%d\n",mim);
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        q.pop();
        if(a[i][j]=='#'){
            mi=min(dis[i][j]-1,mi);
            continue;
        }
            ii=i+1;
            jj=j;
            if(ii<1 || ii>n || jj<1 || jj>m)continue;
            if(dis[i][j]+1>=dis[ii][jj])continue;
            dis[ii][jj]=dis[i][j]+1;
            q.push({ii,jj});

    }
    if(mi==1e9){
        mi=n-mim;
    }
    //printf("%d\n",mi);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='X'){
                if(a[i+mi][j]=='X')a[i+mi][j]='S';
            else
                a[i+mi][j]='R';
                a[i][j]='.';
            }
            if(a[i][j]=='S'){
                if(a[i+mi][j]=='X')a[i+mi][j]='S';
            else
                a[i+mi][j]='R';
                a[i][j]='R';
            }
            if(a[i][j]=='R'){
                printf("X");
                continue;
            }
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
/*
5 6
.XXXX.
...X..
......
#..###
######
*/
