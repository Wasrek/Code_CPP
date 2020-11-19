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
   if(p[i]==i) return i;
   return p[i]=fin(p[i]);
}
int main()
{
    int n,m,i,x,y,px,py;
    scanf(" %d %d",&n,&m);
    for(i=1;i<=n;i++) p[i]=i;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    while(m--){
        scanf("%d %d",&x,&y);
        px=fin(x),py=fin(y);
        if(px==py) printf("-1\n");
        else if(a[px]>a[py]){
                printf("%d\n",px);
                p[py]=px;
                a[px]+=(a[py]/2);
        }
        else if(a[py]>a[px]){
                printf("%d\n",py);
                p[px]=py;
                a[py]+=(a[px]/2);
        }
        else if(px<py){
                printf("%d\n",px);
                p[py]=px;
                a[px]+=(a[py]/2);
        }
        else {
                printf("%d\n",py);
                p[px]=py;
                a[py]+=(a[px]/2);
        }
    }

    return 0;
}
