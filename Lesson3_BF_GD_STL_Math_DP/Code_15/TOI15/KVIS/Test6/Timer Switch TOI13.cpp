/*
    TASK:Timer Switch TOI13
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char b[10000000],a[10000000];
int pi[10000000];
int main(){
    int n,i;
    scanf("%d",&n);
    scanf(" %s",b+1);
    for(i=1;i<=n;i++){
        a[i]=a[n+i]=b[i];
    }
    int j=0;
    for(i=2;i<=n;i++){
        if(b[j+1]==b[i])j++;
        pi[i]=j;
    }
//    for(i=2;i<=n;i++){
//        printf("%d ",pi[i]);
//    }
    j=0;
    for(i=2;i<=n*2;i++){
        while(j>0 && b[j+1]!=a[i])j=pi[j];
        if(b[j+1]==a[i])j++;
        if(j==n){printf("%d\n",i-n);return 0;}
    }
}
