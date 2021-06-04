/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    int q,a,b,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&a);
        if(a==100){
            printf("1\n");
            continue;
        }
        b=100-a;
        now=gcd(a,b);
        printf("%d\n",a/now+b/now);
    }
    return 0;
}