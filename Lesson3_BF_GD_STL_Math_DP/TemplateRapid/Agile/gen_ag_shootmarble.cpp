/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
#define MAN 1ll<<20
long long ran(long long l, long long r)
{
    // return l + (rand() % (r - l + 1));
    return rnd.next(l,r);
}
int main(int argc,char* argv[])
{
    // srand(time(0));
    int q,n,st,ts,ma=200000,cnt=0;
    q = atoi(argv[++cnt]);
    st = atoi(argv[++cnt]);
    ts = atoi(argv[++cnt]);
	printf("%d\n",q);
    for(int i=1;i<=q;i++){
        printf("%d\n",ma);
        for(int j=1;j<=ma;j++){
            if(st){
                printf("%d",ran(0,1));
            }else printf("%lld",ran(0,MAN));
            if(j!=ma) printf(" ");
        }
        printf("\n");
    }
    return 0;
}