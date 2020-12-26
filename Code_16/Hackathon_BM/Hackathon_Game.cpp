/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    n-=m;
    if(n<0){
        printf("NEED MORE GEMS!\n");
        return 0;
    }else{
        printf("You get a SCEPTER!\n");
        printf("SSR : %d\n",n/10);
        n%=10;
        printf("SR : %d\n",n/5);
        n%=5;
        printf("R : %d\n",n/2);
        n%=2;
        printf("C : %d\n",n);
    }
    return 0;
}