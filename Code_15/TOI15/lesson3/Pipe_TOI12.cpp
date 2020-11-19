/*
    TASK:Pipe TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long x[15100],y[15100],a[15100];
int main(){
    long long n,k,i,l,mi,w=0,j,th;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
        a[i]=1<<30;
    }
    for(i=1;i<n;i++){
        mi=1e9;
        for(j=i+1;j<=n;j++){
            if(a[j]>abs(x[i]-x[j])+abs(y[i]-y[j])){
                a[j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
            if(mi>a[j])mi=a[j],l=j;
        }
        swap(x[i+1],x[l]);
        swap(y[i+1],y[l]);
        swap(a[i+1],a[l]);
    }
    int cou=0;
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        cou++;
        w+=a[i];
        if(cou==n-k)break;
    }
    printf("%lld\n",w);
}
