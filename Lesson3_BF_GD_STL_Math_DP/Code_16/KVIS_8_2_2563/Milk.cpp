/*
    TASK:Milk
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int p[100010];
int fin(int i){
    if(p[i]==i) {return i;}
    else {return p[i]=fin(p[i]);}
}
int main()
{
    int n,q,a,b;
    char opr;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        if(opr=='q'){
            a=fin(a);
            b=fin(b);
            if(a==b)printf("yes\n");
            else printf("no\n");
        }else{
            a=fin(a);
            b=fin(b);
            p[a]=b;
        }
    }
    return 0;
}