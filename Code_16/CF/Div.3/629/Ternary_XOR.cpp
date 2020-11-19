/*
    TASK:Ternary XOR
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[50010],b1[50010],b2[50010];
int main()
{
    int q,n,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        scanf(" %s",a+1);
        ch=1;
        for(int i=1;i<=n;i++){
            a[i]-='0';
            if(ch){
                if(a[i]==1){
                    b1[i]=1;
                    b2[i]=0;
                    ch=0;
                }else if(a[i]==2){
                    b1[i]=1;
                    b2[i]=1;
                }else{
                    b1[i]=0;
                    b2[i]=0;
                }
            }else{
                if(a[i]==1){
                    b2[i]=1;
                    b1[i]=0;
                }else if(a[i]==2){
                    b2[i]=2;
                    b1[i]=0;
                }else{
                    b1[i]=b2[i]=0;
                }
            }
            b1[i]+='0';
            b2[i]+='0';
        }
        for(int i=1;i<=n;i++){
            printf("%c",b1[i]);
        }
        printf("\n");
        for(int i=1;i<=n;i++){
            printf("%c",b2[i]);
        }
        printf("\n");
    }
    return 0;
}