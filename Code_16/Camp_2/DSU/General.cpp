/*
    TASK:General
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],p[100010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[i]=i;
    }
    while(m--){
        scanf("%d %d",&x,&y);
        x=fin(x);
        y=fin(y);
        if(x==y){
            printf("-1\n");
            continue;
        }
        if(a[x]>a[y]){
            a[x]+=(a[y]/2);
            p[y]=x;
            printf("%d\n",x);
        }else if(a[y]>a[x]){
            a[y]+=(a[x]/2);
            p[x]=y;
            printf("%d\n",y);
        }else if(x<y){
            a[x]+=(a[y]/2);
            p[y]=x;
            printf("%d\n",x);
        }else {
            a[y]+=(a[x]/2);
            p[x]=y;
            printf("%d\n",y);
        }
    }
    return 0;
}