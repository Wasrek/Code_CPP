/*
    TASK:Observatory
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[2010][2010],c[2010][2010],qs[2010][2010],st[2010][2010];
int main(){
    int m,n,k,i,j,now,Ma=-2e9;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            c[i][j]=c[i][j-1]+a[i][j];
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            st[i][j]=st[i-1][j-1]+c[i][j];
        }
    }
    for(i=1;i<=n-k+1;i++){
        for(j=1;j<=m-k+1;j++){
            now=st[i+k-1][j+k-1]-(qs[i+k-1][j-1]-qs[i-1][j-1])-st[i-1][j-1];
            Ma=max(Ma,now);
        }
    }
    for(i=1;i<=n;i++){
        reverse(a[i]+1,a[i]+m+1);
        for(j=1;j<=m;j++){
            c[i][j]=c[i][j-1]+a[i][j];
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            st[i][j]=st[i-1][j-1]+c[i][j];
        }
    }
    for(i=1;i<=n-k+1;i++){
        for(j=1;j<=m-k+1;j++){
            now=st[i+k-1][j+k-1]-(qs[i+k-1][j-1]-qs[i-1][j-1])-st[i-1][j-1];
            Ma=max(Ma,now);
        }
    }
    printf("%d\n",Ma);

}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
