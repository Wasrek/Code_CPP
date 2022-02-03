/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[5];
long long fw[500100];
void upd(long long a,long long v){
    for(int i=a;i<=500000;i+=(i&-i)) fw[i]+=v;
}
long long que(int a){
    long long now=0;
    for(int i=a;i>0;i-=(i&-i)) now+=fw[i];
    return now;
}
int main()
{
    long long n,m,v,a,b;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf(" %s",s+1);
        if(s[1]=='Y'){
            scanf("%lld %lld %lld",&v,&a,&b);
            if(b<a) swap(a,b);
            upd(a,v);
            upd(b+1,-v);
        }else{
            scanf("%lld",&a);
            printf("%lld\n",que(a));
        }
    }
    return 0;
}