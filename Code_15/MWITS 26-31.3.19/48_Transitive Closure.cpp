/*
    TASK:48_Transitive Closure
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[510][510];
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)a[i][j]=1e9;
        }
    }
    for(k=0;k<n;k++){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);        }
    }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=1e9)
            printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}
