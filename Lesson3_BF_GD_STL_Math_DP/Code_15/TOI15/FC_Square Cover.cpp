/*
    TASK:FC_Square Cover
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int x[25],y[25];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    sort(x+1,x+n+1);
    sort(y+1,y+1+n);
    int a;
    a=max(x[n]-x[1],y[n]-y[1]);
    a*=a;
    printf("%d\n",a);
}
