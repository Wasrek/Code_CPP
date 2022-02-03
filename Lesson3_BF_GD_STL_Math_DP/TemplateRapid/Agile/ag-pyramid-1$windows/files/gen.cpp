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
    int cnt=0,N;
    N = atoi(argv[++cnt]);
    printf("5000\n");
    N*=1000000;
    for(int i=N;i>=N-5000+1;i--){
        printf("%d\n",i);
    }
    return 0;
}