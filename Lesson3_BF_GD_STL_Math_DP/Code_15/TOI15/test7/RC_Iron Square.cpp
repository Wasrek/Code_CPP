/*
    TASK:RC_Iron Square
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int qs[110][110];
int main(){
    int r,c,k,i,j,ii,jj,now;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='*' && i!=1 && i!=r && j!=1 && j!=c)qs[i][j]=1;
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    int ans=0;
    k-=2;
    for(i=k+1;i<=r-1;i++){
        for(j=k+1;j<=c-1;j++){
            now=qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k];
            if(now>ans)ii=i,jj=j,ans=now;
        }
    }
    a[ii+1][jj+1]='+';
    a[ii+1][jj-k]='+';
    a[ii-k][jj+1]='+';
    a[ii-k][jj-k]='+';
//    for(i=1;i<=r;i++){
//        for(j=1;j<=c;j++){
//            printf("%c",a[i][j]);
//        }
//        printf("\n");
//    }
    ii-=k;
    jj-=k;
    //printf("%d %d\n",ii,jj);
    k+=2;
    for(j=jj+1;j<jj+k-1;j++){
        a[ii][j]=a[ii+k-1][j]='-';
    }
    for(i=ii+1;i<ii+k-1;i++){
        a[i][jj]=a[i][jj+k-1]='|';
    }
    printf("%d\n",ans);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }

}
/*
7 6 4
......
.*.*.*
......
.*.*..
..*...
..*...
*....*
*/
