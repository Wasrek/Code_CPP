/*
    TASK:Milk
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    char w;
    int q,n,i,x,y;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    while(q--){
        scanf(" %c %d %d",&w,&x,&y);
        if(w=='q'){
            if(fin(x)==fin(y))printf("yes\n");
            else printf("no\n");
        }else if(w=='c'){
            p[fin(x)]=fin(y);
        }
    }
    return 0;
}
