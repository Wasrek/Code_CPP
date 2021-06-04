/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[55];
int main()
{
    int q,n,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ch=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]!=i) ch=1;
        }
        if(!ch){
            printf("0\n");
            continue;
        }
        if(a[1]==1 || a[n]==n){
            printf("1\n");
            continue;
        }
        if(a[n]!=1 || a[1]!=n){
            printf("2\n");
            continue;
        }
        printf("3\n");
    }
    return 0;
}