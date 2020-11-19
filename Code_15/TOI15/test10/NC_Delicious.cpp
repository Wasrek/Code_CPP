/*
    TASK:NC_Delicious
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],lis[100010];
int main(){
    long long n,i,ub,ch=0,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    long long cnt=0;
    for(i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(a[i]<=0)continue;
        //printf("%lld ",a[i]);
        ub=lower_bound(lis,lis+cnt,a[i])-lis;
        if(i==n){printf("%lld",ub+1);return 0;}
        if(ub==cnt)cnt++;
        lis[ub]=a[i];
    }
}
/*
5
10
-2
-30
40
-1
*/
/*
12
10 -2 -10 6 9 7 -5 -2 1 2 3 4
*/
