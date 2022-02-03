/*
    TASK:Longest
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int l[1010][1010],r[1010][1010],u[1010][1010],d[1010][1010];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        // printf("here");
        for(int i=1;i<=n;i++){
            scanf(" %s",a[i]+1);
            for(int j=1;j<=m;j++){
                // printf("here\n");
                if(a[i][j]=='0'){l[i][j]=r[i][j]=u[i][j]=d[i][j]=0;continue;}
                u[i][j]=u[i-1][j]+1;
                l[i][j]=l[i][j-1]+1;
            }
        }
        // printf("here");
        for(int i=1;i<=n;i++){
            l[i][m+1]=r[i][m+1]=u[i][m+1]=d[i][m+1]=0;
        }
        for(int j=1;j<=m;j++){
            l[n+1][j]=r[n+1][j]=u[n+1][j]=d[n+1][j]=0;
        }
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(a[i][j]=='0')continue;
                d[i][j]=d[i+1][j]+1;
                r[i][j]=r[i][j+1]+1;
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         printf("%d ",d[i][j]);
        //     }
        //     printf("\n");
        // }
        int ma=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='0') continue;
                ma=max(ma,max(u[i][j]+l[i][j]-1,max(u[i][j]+r[i][j]-1,max(d[i][j]+l[i][j]-1,d[i][j]+r[i][j]-1))));
            }
        }
        printf("%d\n",ma);
    }
    return 0;
}