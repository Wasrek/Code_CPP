/*
    TASK:Sink hill
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],l[1010][1010],r[1010][1010],u[1010][1010],d[1010][1010],s[1010][1010];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
    int n,m,i,j,last,Max=0,mi,mj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(j!=1){
            if(a[i][j]>=a[i][j-1])l[i][j]+=(l[i][j-1]+1);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            if(j!=m){
            if(a[i][j]>=a[i][j+1])r[i][j]+=(r[i][j+1]+1);
            }
        }
    }
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
            if(i!=1){
            if(a[i][j]>=a[i-1][j])u[i][j]+=(u[i-1][j]+1);
            }
        }
    }
    for(j=1;j<=m;j++){
        for(i=n;i>=1;i--){
            if(i!=n){
            if(a[i][j]>=a[i+1][j])d[i][j]+=(d[i+1][j]+1);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            s[i][j]=r[i][j]+l[i][j]+u[i][j]+d[i][j]+1;
            //printf("%d ",s[i][j]);
            if(s[i][j]>Max)Max=s[i][j],mi=i,mj=j;
        }
        //printf("\n");
    }
    printf("%d\n%d %d\n",Max,mi,mj);
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    memset(d,0,sizeof d);
    memset(u,0,sizeof u);
    memset(s,0,sizeof s);
    }

    return 0;
}
/*
2
4 6
7 3 5 7 2 4
1 5 2 6 2 10
8 4 1 2 3 2
10 7 10 7 3 8
4 4
5 4 1 2
4 2 2 3
4 4 3 5
1 2 2 6
*/
