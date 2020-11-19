/*
    TASK:Sandglass
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==0){
        printf("error\n");
        return 0;
    }
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int j=1;j<=n-(i*2);j++){
            printf("*");
        }
        for(int j=0;j<i;j++){
            printf(" ");
        }
        printf("\n");
    }
    for(int i=n/2-1;i>=0;i--){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int j=1;j<=n-(i*2);j++){
            printf("*");
        }
        for(int j=0;j<i;j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}