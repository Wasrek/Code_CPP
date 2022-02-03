/*
    TASK:FC_Distance
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long x[500010],y[500010],dpx[500010],dpy[500010];
int main(){
    int i,n;
    long long ansx=0,ansy=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
//    for(i=1;i<=n;i++){
//        printf("%d ",x[i]);
//    }
//    printf("\n");
//    for(i=1;i<=n;i++){
//        printf("%d ",y[i]);
//    }
//    printf("\n");
    for(i=2;i<=n;i++){
        dpx[i]=((x[i]-x[i-1]))*(i-1)+dpx[i-1];
        dpy[i]=((y[i]-y[i-1]))*(i-1)+dpy[i-1];
        //printf("%lld %lld\n",dpx[i],dpy[i]);
    }
    for(i=1;i<=n;i++){
        dpx[i]+=dpx[i-1];
        dpy[i]+=dpy[i-1];
    }
    printf("%lld\n",dpx[n]+dpy[n]);
    return 0;

}
/*
5
3 3
5 1
4 4
1 3
4 7
*/
