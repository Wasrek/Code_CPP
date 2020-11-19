/*
    TASK:Greed Wall of Siam
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int main(){
    long long n,x,ch=0;
    scanf("%lld",&n);
    long long ans=0,ans1=0;
    while(n--){
        scanf("%lld",&x);
        if(x==0)continue;
        if(ch==0){ans=ans1=x,ch=1;continue;}
        ans=gcd(ans,x);
        ans1+=x;
    }
    if(ans==0 && ans1==0){printf("0\n");return 0;}
    printf("%lld\n",ans1/ans);
}
