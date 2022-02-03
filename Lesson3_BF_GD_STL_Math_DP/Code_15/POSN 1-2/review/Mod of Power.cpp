/*
    TASK:Mod of Power
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long mop(long long a,long long b,long long c){
    if(b==1)return a%c;
    long long n=mop(a,b/2,c);
    if(b%2==0)return (n*n)%c;
    if(b%2==1)return (n*n*a)%c;
}
int main(){
    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    long long ans=mop(a,b,c);
    printf("%lld",ans);
}
