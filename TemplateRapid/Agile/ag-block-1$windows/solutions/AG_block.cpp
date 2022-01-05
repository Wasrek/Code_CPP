/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int fw[2020];
void upd(int st, int ed){
    for(int i=st;i<=2000;i+=(i&-i)){
        fw[i]++;
    }
    for(int i=ed+1;i<=2000;i+=(i&-i)){
        fw[i]--;
    }
}
int qy(int u){
    int sum=0;
    for(int i=u;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    return sum;
}
int main()
{
    int n,m,k,q,a,b,l,x;
    scanf("%d %d %d %d",&n,&m,&k,&q);
    int loop=k+q;
    while(loop--){
        scanf("%d %d %d",&x,&a,&b);
        if(x==1){
            scanf("%d",&l);
            upd(a+b,a+b+l-1);
        }else{
            printf("%d\n",qy(a+b));
        }
    }
    return 0;
}