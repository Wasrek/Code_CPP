/*
    TASK:Check Prime
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int n[5000100];
int main(){
    int q,a,m,j,i;
    scanf("%d",&q);
    n[2]=1;
    m=sqrt(5000500);
    for(i=3;i<=m;i+=2){
        n[i]=1;
    }
    for(i=3;i<=m;i+=2){
        if(n[i]){
            for(j=i*i;j<=5000000;j+=i){
                n[j]=0;
            }
        }
    }
    while(q--){
        scanf("%d",&a);
        if(n[a])printf("yes\n");
        else printf("no\n");
    }
}
