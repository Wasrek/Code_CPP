/*
    TASK:NC_Hail Three
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],row[1010][2],col[1010][2];
int main(){
    int n,m,i,j,ans=1<<30,now;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        row[i][0]=row[i][1]=1<<30;
    }
    for(i=0;i<m;i++){
        col[i][0]=col[i][1]=1<<30;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]<row[i][0])
                row[i][1]=row[i][0],row[i][0]=a[i][j];
            else if(a[i][j]<row[i][1])
                row[i][1]=a[i][j];
            if(a[i][j]<col[j][0])
                col[j][1]=col[j][0],col[j][0]=a[i][j];
            else if(a[i][j]<col[j][1])
                col[j][1]=a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            now=a[i][j];
            if(a[i][j]==row[i][0]) now+=row[i][1];
            else                   now+=row[i][0];
            if(a[i][j]==col[j][0]) now+=col[j][1];
            else                   now+=col[j][0];
            ans=min(ans,now);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 7
99 45 21 32 11 85 15
33 21 12 15 47 85 65
32 54 75 65 85 95 85
12 91 42 32 52 76 61
37 22 40 62 10 25 32
*/
