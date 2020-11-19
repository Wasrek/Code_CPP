/*
    TASK:General
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100],a[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,m,i,j,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=i;
    }
    while(m--){
        scanf("%d %d",&x,&y);
        if(fin(x)==fin(y)){
            printf("-1\n");
            continue;
        }
        if(a[fin(x)]>a[fin(y)]){
            a[fin(x)]+=a[fin(y)]/2;
            p[fin(y)]=fin(x);
            printf("%d\n",fin(x));continue;
        }else if(a[fin(y)]>a[fin(x)]){
            a[fin(y)]+=a[fin(x)]/2;
            p[fin(x)]=fin(y);
            printf("%d\n",fin(y));continue;
        }else {
            if(fin(y)<fin(x)){
                p[fin(x)]=fin(y);
                printf("%d\n",fin(y));continue;
            }else{
                p[fin(y)]=fin(x);
                printf("%d\n",fin(x));continue;
            }
        }
    }
    return 0;
}
