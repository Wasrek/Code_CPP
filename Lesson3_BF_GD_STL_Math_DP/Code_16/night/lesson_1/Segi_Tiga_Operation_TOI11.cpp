/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int c0,c1,c2;
};
A a[300][300];
char s[300];
int main()
{
    int q=20,n;
    while(q--){
        scanf("%d",&n);
        scanf(" %s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='0') a[i][i].c0=1,a[i][i].c1=0,a[i][i].c2=0;
            if(s[i]=='1') a[i][i].c0=0,a[i][i].c1=1,a[i][i].c2=0;
            if(s[i]=='2') a[i][i].c0=0,a[i][i].c1=0,a[i][i].c2=1;
        }
        for(int k=2;k<=n;k++){
            for(int i=1;i<=n-k+1;i++){
                int j=i+k-1;
                a[i][j].c0=a[i][j].c1=a[i][j].c2=0;
                for(int l=i;l<j;l++){
                    if(a[i][l].c0==1 && a[l+1][j].c0==1) a[i][j].c2=1;
                    if(a[i][l].c0==1 && a[l+1][j].c1==1) a[i][j].c1=1;
                    if(a[i][l].c0==1 && a[l+1][j].c2==1) a[i][j].c0=1;
                    if(a[i][l].c1==1 && a[l+1][j].c0==1) a[i][j].c2=1;
                    if(a[i][l].c1==1 && a[l+1][j].c1==1) a[i][j].c1=1;
                    if(a[i][l].c1==1 && a[l+1][j].c2==1) a[i][j].c1=1;
                    if(a[i][l].c2==1 && a[l+1][j].c0==1) a[i][j].c1=1;
                    if(a[i][l].c2==1 && a[l+1][j].c1==1) a[i][j].c2=1;
                    if(a[i][l].c2==1 && a[l+1][j].c2==1) a[i][j].c1=1;
                    // printf("%d %d %d  %d %d %d\n",i,l,a[i][l].c0,l+1,j,a[l+1][j].c2);
                }
                // printf("%d %d %d %d %d %d\n",k,i,j,a[i][j].c0,a[i][j].c1,a[i][j].c2);
            }
        }
        if(a[1][n].c0){
            printf("yes\n");
        }else printf("no\n");
    }
    return 0;
}