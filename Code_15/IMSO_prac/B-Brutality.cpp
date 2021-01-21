/*
    TASK:B-Brutality
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long a,m;
    bool operator <(const A & o)const{
        if(m!=o.m){
            return m<o.m;
        }else {
            return a>o.a;
        }
    }
};
char s[200010];
A b[200010];
int main()
{
    long long n,now,k,cnt=0,ma=0;
    scanf("%lld %lld",&n,&k);
    long long sum=0,i,j;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&b[i].a);
    }
    scanf(" %s",s+1);
//    printf("-");
    for(i=1; i<=n; i++)
    {
        if(s[i]!=s[i-1])b[i].m=++cnt;
        else b[i].m=cnt;
    }
//    printf("-");
    sort(b+1,b+1+n);
//    printf("-");
    cnt=0;
    for(i=1;i<=n;i++){
//        printf("%lld %lld\n",b[i].a,b[i].m);
        if(b[i].m==b[i-1].m)cnt++;
        else cnt=1;
        if(cnt>k)continue;
        ma+=b[i].a;
        if(cnt==k || (cnt<k && b[i].m!=b[i+1].m))sum+=ma,ma=0;
    }
    printf("%lld\n",sum);
    return 0;
}
