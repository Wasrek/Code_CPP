/*
    TASK:Ctrl F
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int pre[1010];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    int j=0;
    for(int i=2;i<=m;i++){
        while(j>0 && b[j+1]!=b[i])j=pre[j];
        if(b[j+1]==b[i])j++;
        pre[i]=j;
        // printf("%d ",pre[i]);
    }
    // printf("here\n");
    int cnt=0;
    for(int i=1,j=0;i<=n;i++){
        while(j>0 && b[j+1]!=a[i]) j=pre[j];
        if(b[j+1]==a[i]) j++;
        if(j==m){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}