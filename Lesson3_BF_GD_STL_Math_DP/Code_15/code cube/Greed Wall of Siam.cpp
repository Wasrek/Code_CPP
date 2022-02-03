/*
    TASK:Greed Wall of Siam
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a==0)return b;
    if(b==0)return a;
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main(){
    long long n,now,g;
    long long sum=0;
    scanf("%lld %lld",&n,&g);
    n--;
    sum+=g;
    while(n--){
        scanf("%lld",&now);
        sum+=now;
        g=gcd(g,now);
    }
    printf("%lld\n",sum/g);

}
