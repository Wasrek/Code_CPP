/*
    TASK:Alchemy
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[100100];
int main()
{
    // freopen("alchemy_input.txt","r",stdin);
    // freopen("output_alchemy_last.txt","w",stdout);
    int Q,q,n,cnta,cntb;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d",&n);
        scanf(" %s",a);
        cnta=cntb=0;
        for(int i=0;i<n;i++){
            if(a[i]=='A')cnta++;
            if(a[i]=='B')cntb++;
        }
        printf("Case #%d: ",q);
        if(abs(cnta-cntb)==1){
            printf("Y\n");
        }else printf("N\n");
    }
    return 0;
}