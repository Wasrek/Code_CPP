/*
    TASK:Least Common Multiple
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
long long gcd(long long a,long long b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
using namespace std;
int main(){
    long long a,b,ans;
    scanf("%lld %lld",&a,&b);
    if(a==0){
        ans=b;
    }else
    if(b==0){
        ans=a;
    }else
    ans=gcd(a,b);
    printf("%lld\n",(a*b)/ans);
    return 0;
}
