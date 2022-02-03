/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
#define maxN 200000
const int mi=-1*1e9, ma=1e9, maint=2e9;
long long ran(long long l, long long r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
int main(int argc,char* argv[])
{
// int main(){
    // srand(time(0));
    registerGen(argc,argv,1);
    long long cnt=0,Q,N,I,n,ans,gr,diff;
    long long maa,mii,xaa,xii;
    // scanf("%d %d %d",&Q,&N,&I);
    Q = atoi(argv[++cnt]);
	N = atoi(argv[++cnt]);
    I = atoi(argv[++cnt]);
    printf("%lld\n",Q);
    while(Q--){
        n=ran(N-1,N);
        if(I<=2){
            n=ran(210,250);
        }
        ans=ran(1,n-100);
        // int ans=3;
        gr=ceil((double)n/ans);
        diff=maint/ans;
        maa=mi+diff-1;
        mii=mi;
        xaa=ma;
        xii=ma-diff+1;
        printf("%lld\n",n);
        for(int i=1;i<=n;i++){
             printf("%lld %lld\n",ran(xii,xaa),ran(mii,maa));
             if(i%gr==0){
                 mii+=diff;
                 maa+=diff;
                 xaa-=diff;
                 xii-=diff;
             }
        }
    }
    return 0;
}