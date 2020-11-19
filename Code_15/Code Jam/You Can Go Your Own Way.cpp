/*
    TASK:You Can Go Your Own Way
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[100100],b[100100];
int main(){
    int q,t,n,i,j,ni,nj;
    scanf("%d",&t);
    for(q=1;q<=t;q++){
        scanf("%d",&n,&n);
        ni=nj=n-1;
        for(i=1;i<=2*n-2;i++){
        scanf(" %c",&a[i]);
        if(a[i]=='E')b[i]='S';
        else
        if(a[i]=='S')b[i]='E';
        }
        printf("Case #%d: ",q);
        for(j=1;j<=2*n-2;j++)printf("%c",b[j]);
        printf("\n");
    }
    return 0;
}
