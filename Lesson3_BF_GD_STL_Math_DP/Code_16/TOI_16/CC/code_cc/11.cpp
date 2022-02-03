/*
    TASK:Age of Altron 
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],ok[1010],qs[1010][1010];
int main()
{
    int n,m,k,all=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            qs[i][j]=qs[i][j-1]+a[i][j];
            if(!a[i][j]) ok[i]++,all++;
        }
        ok[i]+=ok[i-1];
        // printf("%d\n",ok[i]);
    }
    for(int i=n;i>=1;i--){
        for(int j=k;j<=m;j++){
            if(qs[i][j]-qs[i][j-k]<=all-ok[i]){
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}