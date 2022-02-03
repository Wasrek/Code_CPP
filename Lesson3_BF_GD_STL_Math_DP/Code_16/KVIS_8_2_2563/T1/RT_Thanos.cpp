/*
    TASK:RT_Thanos
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[3010][3010];
int dis[3010][3010];
int ch[3010][3010];
int main()
{
    int n,m,now,sti,stj,eni,enj;
    scanf("%d %d",&n,&m);
    sti=stj=max(n,m);
    eni=enj=0;
    for(int i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++){
            if(a[i][j]=='X'){
                sti=min(sti,i);
                stj=min(stj,j);
                eni=max(eni,i);
                enj=max(enj,j);
                ch[i][j]=2;
            }
        }
    }
    for(int j=stj;j<=enj;j++){
        for(int i=n;i>=1;i--){
            if(a[i+1][j]=='#' && a[i][j]!='#')dis[i][j]=1;
            else if(a[i][j]!='#' && a[i+1][j]!='#')dis[i][j]=dis[i+1][j]+1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",dis[i][j]);
    //     }
    //     printf("\n");
    // }
    now=1e9;
    for(int i=sti;i<=eni;i++){
        for(int j=stj;j<=enj;j++){
            if(a[i][j]=='X'){
                now=min(now,dis[i][j]);
            }
        }
    }
    now--;
    // printf("%d\n",now);
    for(int i=eni;i>=sti;i--){
        for(int j=stj;j<=enj;j++){
            if(ch[i][j]==2){
                a[i+now][j]='X';
                a[i][j]='.';
            }
        }
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
5 6
.XXXX.
...X..
......
#..###
######
*/