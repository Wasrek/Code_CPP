/*
    TASK:Q_Game2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int n[220][220],Min[220][220],Max[220][220];
int main()
{
    int h,w,i,j;
    scanf("%d %d",&h,&w);
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            scanf("%d",&n[i][j]);
            Max[i][j]=Min[i][j]=n[i][j];
        }
    }
    for(i=1;i<=h;i++){
        for(j=w;j>=1;j--){
            Max[i][j]+=max(Max[i][j+1],Max[i-1][j]);
        }
    }
    /*for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            printf("%d ",Max[i][j]);
        }
        printf("\n");
    }*/
    for(i=1;i<=h;i++){
        for(j=w;j>=1;j--){
            int mi = 1e9;
            if(i>=1 && j+1<=w){
                mi = min(mi,Min[i][j+1]);
            }
            if(i-1>=1 && j<=w)
                mi = min(mi,Min[i-1][j]);

            if(mi == 1e9)
                mi = 0;
            Min[i][j]+=mi;
        }
    }
    /*for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            printf("%d ",Min[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",Max[h][1]-Min[h][1]);
    return 0;
}
/*
4 4
3 3 3 3
2 2 1 3
0 1 1 3
0 0 0 0
*/
