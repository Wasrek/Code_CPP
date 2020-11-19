/*
    TASK:A. Little Artem
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,r,c;
    char ch,ch1;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(i==1 && j==1) printf("W");
                else printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}