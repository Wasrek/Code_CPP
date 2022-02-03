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
    int n,m,k,q,ch,cnt=0;
    n = atoi(argv[++cnt]);
	m = atoi(argv[++cnt]);
    k = atoi(argv[++cnt]);
	q = atoi(argv[++cnt]);
    ch = atoi(argv[++cnt]);
	printf("%d %d %d %d\n",n,m,k,q);
    int ask=q-(n+m-1);
    int loop=ask+k,rd,a,b;
    if(ch==1) ask=0, loop=k;
    while(loop--){
        rd=1;
        if(ask){
            rd=ran(0,1);
            if(rd==0) ask--;
        }
        a=ran(1,n);
        b=ran(1,m);
        if(rd==1){//put
            printf("1 %d %d %d\n",a,b,ran(1,m-b+1));
        }else{//ask
            printf("2 %d %d\n",a,b);
        }
    }
    int now;
    for(int i=2;i<=n+m;i++){
        now=ran(1,i/2);
        printf("2 %d %d\n",now,i-now);
    }
    if(ch==1){
        for(int i=2;i<=n+m;i++){
            now=ran(1,i/2);
            printf("2 %d %d\n",now,i-now);
        }
    }
    return 0;
}