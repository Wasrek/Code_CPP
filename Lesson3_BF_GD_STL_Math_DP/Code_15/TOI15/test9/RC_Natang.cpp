/*
    TASK:RC_Natang
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2010][2010];
void crew(int id,int x,int y,int w,int h){
    int ii,jj;
    ii=min(n,x+w-1);
    jj=min(m,y+h-1);
    for(int i=x;i<=ii;i++){
        for(int j=y;j<=jj;j++){
            a[i][j]=id;
        }
    }
    return ;
}
int main(){
    char fun;
    int id,x,y,w,h,ans,i,j,cou=0;
    while(1){
        scanf(" %c",&fun);
        if(fun=='T')return 0;
        if(fun=='I'){
            scanf(" %d %d",&m,&n);
            n--;m--;
        }else
        if(fun=='C'){
            scanf(" %d %d %d %d %d",&id,&y,&x,&h,&w);
            crew(id,x,y,w,h);
        }else
        if(fun=='G'){
            scanf(" %d %d",&y,&x);
            printf("%d\n",a[x][y]);
        }
//        printf("%d\n",++cou);
//        for(i=0;i<=n;i++){
//            for(j=0;j<=m;j++){
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
    }
}

/*
I 10 5
C 23 1 1 3 4
C 194 3 2 9 9
G 1 2
G 3 4
T
*/
