/*
    TASK:Ultimate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
    int r,c,Max=0,i,j;
    char d;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf(" %c",&d);
            if(d=='#'){
                a[i][j]=0;
            }else{
               a[i][j]=min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1])+1;
            }
            if(a[i][j]>Max)Max=a[i][j];
        }
    }
    printf("%d\n",Max);

    return 0;
}
