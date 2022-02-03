/*
    TASK: Melt Choco
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long l,r,ans;
long long play(long long n){
   if(n<=1) return 1;
   return 2*play(n/2)+1;
}
void melt(long long n,long long ll,long rr){
   if(ll>r||rr<l) return ;
   if(n<=1){
    ans+=n; return ;
   }
   melt(n/2,ll,ll+(rr-ll)/2-1);
   melt(n%2,(ll+rr)/2,(ll+rr)/2);
   melt(n/2,ll+(rr-ll)/2+1,rr);
}
int main()
{
    long long n,len;
    scanf("%lld %lld %lld",&n,&l,&r);
    len = play(n);
    melt(n,1,len);
    printf("%lld\n",ans);
    return 0;
}
