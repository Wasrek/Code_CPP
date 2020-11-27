/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[110];
int main()
{
    int q,lena,j,ii,jj;
    scanf("%d",&q);
    scanf(" %s",a+1);
    lena=strlen(a+1);
    for(int i=1;i<=lena;i++){
        if(a[i]=='*') j=i;
    }
    // printf("%d\n",j);
    while(q--){
        scanf(" %s",b+1);
        if(strlen(b+1)<lena-1){
            printf("No\n");
            continue;
        }
        for(int i=1;i<j;i++){
            if(a[i]!=b[i]){
                printf("No\n");
                goto jump;
            }
        }
        ii=lena,jj=strlen(b+1);
        while(ii>j){
            if(a[ii]!=b[jj]){
                printf("No\n");
                goto jump;
            }
            ii--,jj--;
        }
        printf("Yes\n");
        jump:;
    }
    return 0;
}