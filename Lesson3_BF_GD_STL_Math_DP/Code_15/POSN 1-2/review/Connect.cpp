/*
    TASK:Connect
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],p[100100];
int fin(int i){
    if(p[i]==i)return i;
    else return p[i]=fin(p[i]);
}
int main(){
    int n,k,q,i;
    scanf("%d %d %d",&n,&k,&q);
    for(i=0;i<=n;i++)p[i]=i;
    int x,y;
    while(k--){
        scanf("%d %d",&x,&y);
        p[fin(x)]=fin(y);
    }
    while(q--){
        scanf("%d %d",&x,&y);
        if(fin(p[x])==fin(p[y]))printf("yes\n");
        else{printf("no\n");}
    }
}
