/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[5];
long long fw[750100];
void upd(long long a,long long v){
    for(int i=a;i<=750000;i+=(i&-i)) fw[i]+=v;
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
        if(s[1]=='B'){
            scanf("%lld %lld",&v,&a);
            upd(a,v);
        }else{
            scanf("%lld %lld",&a,&b);
            printf("%lld\n",que(b)-que(a-1));
        }
    }
    return 0;
}