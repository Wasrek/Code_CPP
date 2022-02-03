/*
    TASK:Schedule_TOI8
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int d,v;
};
A a[1010][1010];
int va[1010],vb[1010];
int main()
{
    int t,n,nowv,nowd,nowvj,nowdj;
    scanf("%d",&t);
    scanf("%d",&n);
    a[0][0].d=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&va[i]);
        a[i][0].v=va[i];
        if(a[i][0].v+a[i-1][0].v>t){
            a[i][0].d=a[i-1][0].d+1;
        }else
        a[i][0].v+=a[i-1][0].v,a[i][0].d=a[i-1][0].d;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&vb[i]);
        a[0][i].v=vb[i];
        if(a[0][i].v+a[0][i-1].v>t){
            a[0][i].d=a[0][i-1].d+1;
        }else
        a[0][i].v+=a[0][i-1].v,a[0][i].d=a[0][i-1].d;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            nowd=a[i-1][j].d;
            if(a[i-1][j].v+va[i]<=t)
            nowv=a[i-1][j].v+va[i];
            else nowv=va[i],nowd++;
            nowdj=a[i][j-1].d;
            if(a[i][j-1].v+vb[j]<=t)
            nowvj=a[i][j-1].v+vb[j];
            else nowvj=vb[j],nowdj++;
            if(nowd<nowdj){
                a[i][j].d=nowd;
                a[i][j].v=nowv;
            }else if(nowdj<nowd){
                a[i][j].d=nowdj;
                a[i][j].v=nowvj;
            }else{
                a[i][j].d=nowd;
                a[i][j].v=min(nowv,nowvj);
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         printf("%d ",a[i][j].d);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         printf("%d ",a[i][j].v);
    //     }
    //     printf("\n");
    // }
    printf("%d\n%d\n",a[n][n].d,a[n][n].v);
    return 0;

}