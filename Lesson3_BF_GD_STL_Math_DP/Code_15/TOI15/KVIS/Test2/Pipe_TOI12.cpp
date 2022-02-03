/*
    TASK:Pipe TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< long long> h;
long long x[15100],y[15100],a[15100];
int main(){
    long long n,k,w,ans=0,i,j,now,mi,l;
    scanf("%lld %lld",&n,&k);
    w=n-k;
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
        a[i]=1<<30;
    }//MST Prim
    for(i=1;i<n;i++){
        mi=1<<30;
        for(j=i+1;j<=n;j++){
            now=(abs(x[i]-x[j])+abs(y[i]-y[j]));
            if(a[j]>now)a[j]=now;
            if(a[j]<mi)mi=a[j],l=j;
            //printf("0");
        }
        //printf("1");
        swap(x[i+1],x[l]);
        swap(y[i+1],y[l]);
        swap(a[i+1],a[l]);
        //printf("1");
    }
    for(i=1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
    for(i=1;i<=n;i++)h.push(a[i]*-1);
    while(w-- && !h.empty()){
        ans+=h.top()*-1;
        h.pop();
    }
    printf("%lld\n",ans);
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/
