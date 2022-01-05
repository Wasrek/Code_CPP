/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
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
    int cnt=0,N,K;
    N = atoi(argv[++cnt]);
	K = atoi(argv[++cnt]);
    int maxx=1e9;
	printf("%d %d\n",N,K);
    for(int i=1;i<=N;i++){
        if(i==N){
            printf("%d\n",ran(1,maxx));    
        }else printf("%d ",ran(1,maxx));
    }
    return 0;
}