/*
    TASK:Ctrl F 2
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int pre[1000010];
int main()
{
    int n,m,j,cnt=0;
    scanf("%d %d",&n,&m);
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    j=0;
    for(int i=2;i<=m;i++){
        while(j>0 && b[j+1]!=b[i]) j=pre[j];
        if(b[i]==b[j+1])j++;
        pre[i]=j;
        // printf("%d ",pre[i]);
    }
    // printf("\n");
    for(int i=1,j=0;i<=n;i++){
        while(j>0 && b[j+1]!=a[i]) j=pre[j];
        if(a[i]==b[j+1]) j++;
        if(j==m){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}