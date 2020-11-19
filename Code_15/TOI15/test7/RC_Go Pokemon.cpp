/*
    TASK:RC_Go Pokemon
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[25],a[25];
int main(){
    long long n,b,c,ma=-1<<30,sum=0,now,ch=0;
    scanf("%lld",&n);
    while(n--){
        scanf(" %s",s);
        scanf(" %lld %lld",&b,&c);
        b-=(long long)2;
        b=max(b,0ll);
        now=c/b;
        //printf("%lld\n",c/b);
        //printf("%lld %lld %lld\n",now,(2*(now-1)+c),b*now);
        while((2*(now-1)+c)<(b+2)*now)now--;
        //printf("%lld\n",now);
        sum+=now;
        if(now>ma){
            ma=now;
            strcpy(a,s);
        }
    }
    //printf("%d\n",ma);
    printf("%lld\n",sum);
    printf("%s\n",a);
}
/*
4
Caterpie
12 33
Pidjey
12 47
Weedle
12 42
Rattata
25 71
*/
