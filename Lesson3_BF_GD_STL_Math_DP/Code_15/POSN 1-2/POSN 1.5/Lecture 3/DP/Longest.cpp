/*
    TASK:Longest
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],r[1010][1010],l[1010][1010],u[1010][1010],b[1010][1010];
int main()
{
    int q,i,j,n,m,Max,L,R,U,B,N;
    char k;
    scanf("%d",&q);
    while(q--){
        Max=0;
        memset(r,0,sizeof r);
        memset(b,0,sizeof b);
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf(" %c",&k);
                a[i][j]=k-'0';
                if(a[i][j]==0)l[i][j]=0;
                else{
                l[i][j]=l[i][j-1]+a[i][j];
                if(l[i][j]>Max)Max=l[i][j];
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=m;j>=1;j--){
                if(a[i][j]==0)r[i][j]=0;
                else
                r[i][j]=a[i][j]+r[i][j+1];
            }
        }
        for(j=1;j<=m;j++){
            for(i=1;i<=n;i++){
                if(a[i][j]==0)u[i][j]=0;
                else
                u[i][j]=u[i-1][j]+a[i][j];
            }
        }
        for(j=1;j<=m;j++){
            for(i=n;i>=1;i--){
                if(a[i][j]==0)b[i][j]=0;
                else
                b[i][j]=b[i+1][j]+a[i][j];
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]!=0){
                L=l[i][j],R=r[i][j],U=u[i][j],B=b[i][j];
                Max=max(max(max((L+U-1),(L+B-1)),max((R+U-1),(R+B-1))),Max);
                }
            }
        }
        printf("%d\n",Max);

    }

    return 0;
}
/*
2
4 5
11110
11011
01111
11110
2 5
01110
11000
*/
/*
 printf("\nl\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d ",l[i][j]);
            }
            printf("\n");
        }
        printf("\nr\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d ",r[i][j]);
            }
            printf("\n");
        }
        printf("\nu\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d ",u[i][j]);
            }
            printf("\n");
        }
        printf("\nb\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
        printf("\nM\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
*/
