/*
    TASK:Melt Choco
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long play(int n){
    if(n<=1) return 1;
    return play(n/2)*2+1;
}
long long cnt=0,l,r;
void melt(long long n,long long nl,long long nr){
    if(nl>r || nr<l) return;
    if(n<=1){
        cnt+=n;
        return ;
    }
    melt(n%2,(nl+nr)/2,(nl+nr)/2);
    melt(n/2,nl,(nl+nr)/2-1);
    melt(n/2,(nl+nr)/2+1,nr);
}
int main()
{
    long long n;
    scanf("%lld %lld %lld",&n,&l,&r);
    long long len=play(n);
    melt(n,1,len);
    printf("%lld\n",cnt);
    return 0;
}