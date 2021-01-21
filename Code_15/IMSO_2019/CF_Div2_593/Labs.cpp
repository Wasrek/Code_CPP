/*
    TASK:Labs
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2){
        for(int j=1;j<=n;j++){
            a[i][j]=++cnt;
        }
        }else{
            for(int j=n;j>=1;j--){
                a[i][j]=++cnt;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
