/*
    TASK:Q_Auntman
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1},ci[8]={-1,-1,1,1,-2,-2,2,2},cj[8]={-1,1,-1,1,-2,2,-2,2},pi[2]={0,-1},pj[2]={-1,0},chi[4]={-1,-1,-2,-2},chj[4]={-1,1,-2,2};
int main()
{
    int n,m,i,j,cou=0,k,nexti,nextj;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='A'){
                    cou++;
                    for(k=0;k<4;k++){
                        nexti=i+chi[k],nextj=j+chj[k];
                    if(a[nexti][nextj]=='x'){
                            a[i][j]='.',cou--;break;
                    }
                }
                for(k=0;k<2;k++){
                        nexti=i+pi[k],nextj=j+pj[k];
                    if(a[nexti][nextj]=='+'){
                            a[i][j]='.',cou--;break;
                    }
            }
            }
            if(a[i][j]=='+'){
                for(k=0;k<4;k++){
                        nexti=i+di[k],nextj=j+dj[k];
                    if(a[nexti][nextj]=='A')a[nexti][nextj]='.',cou--;
                }
            }
            if(a[i][j]=='x'){
                for(k=0;k<8;k++){
                        nexti=i+ci[k],nextj=j+cj[k];
                    if(a[nexti][nextj]=='A')a[nexti][nextj]='.',cou--;
                }

            }
    }
    }
    printf("%d\n",cou);
    for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
            if(a[i][j]=='x' || a[i][j]=='+')printf(".");
    else
        printf("%c",a[i][j]);
    }
    printf("\n");
    }
}
/*
5 7
A..A...
.A..A..
.Ax.+..
...A...
......A
*/
