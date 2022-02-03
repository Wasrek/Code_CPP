/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
int ran(int l, int r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
int ma=0,mi=2e9,st=ran(2,7);
void rnd_x(int n){
    int j=(1000000-7)/n;
    for(int i=0;i<n;i++){
        if(i<n-1) printf("%d ",st+j*i);
        else printf("%d\n",st+j*i);
        mi=min(mi,st+j*i);
        ma=max(ma,st+j*i);
    }
    return ;
}
int main(int argc,char* argv[])
{
    int N,K,Q,cnt=0;
    N = atoi(argv[++cnt]);
	K = atoi(argv[++cnt]);
    Q = atoi(argv[++cnt]);
    printf("%d %d %d\n",N,K,Q);
    rnd_x(N);
    printf("1 %d\n",ran(2,N));
    for(int i=2;i<=K;i++){
        if(i%2) printf("%d %d\n",i/2,ran(1,N));
        else printf("%d %d\n",ran(N/2,N),ran(1,N));
    }
    for(int i=0;i<Q-2;i++){
        printf("%d\n",mi+st*i);
    }
    printf("%d\n%d\n",ma+mi,ma+1);
    return 0;
}