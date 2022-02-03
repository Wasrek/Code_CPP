/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
long long ran(long long l, long long r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
int main(int argc,char* argv[])
{
    // srand(time(0));
    long long Q,minN,maxN,maxW,minW,N,W,minK,maxK,cnt=0;;
	Q = atoll(argv[++cnt]);
    minN = atoll(argv[++cnt]);
	maxN = atoll(argv[++cnt]);
    minW = atoll(argv[++cnt]);
	maxW = atoll(argv[++cnt]);
    minK = atoll(argv[++cnt]);
	maxK = atoll(argv[++cnt]);
    printf("%lld\n",Q);
    while(Q--){
        N=ran(minN,maxN);
        W=ran(minW,maxW);
        printf("%lld %lld\n",N,W);
        for(long long i=1;i<N;i++){
            if(i<=N-2)printf("%lld ",ran(minK,maxK));
            else printf("%lld\n",ran(minK,maxK));
        }
    }
    return 0;
}