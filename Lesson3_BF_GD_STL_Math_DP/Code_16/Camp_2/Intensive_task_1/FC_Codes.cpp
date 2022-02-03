/*
    TASK:FC_Codes
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[5];
long long a[15],b[15],c[15],ab[110],ac[110],bc[110],abc[1010];
int main()
{
    long long n,cnt=0,r1,r2,r3,r12,r23,r13,r123;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",s+1);
        r1=s[1]-'0';
        r2=s[2]-'0';
        r3=s[3]-'0';
        r12=r1*10+r2;
        r23=r2*10+r3;
        r13=r1*10+r3;
        r123=r1*100+r2*10+r3;
        cnt+=(a[r1]+b[r2]+c[r3]-ab[r12]-bc[r23]-ac[r13]+abc[r123]);
        a[r1]++;
        b[r2]++;
        c[r3]++;
        ab[r12]++;
        ac[r13]++;
        bc[r23]++;
        abc[r123]++;
    }
    printf("%lld\n",cnt);
    return 0;
}