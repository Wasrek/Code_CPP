/*
    TASK:NC_Victuals
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 99877
long long fw[100010],ans[100010];
map<int,int> mp;
void update(int a,int v){
    for(int i=a;i<=100000;i+=(i&-i)){
        fw[i]+=v;
        fw[i]%=mod;
    }
}
void update2(int a,int v){
    for(int i=a;i<=100000;i+=(i&-i)){
        ans[i]+=v;
        ans[i]%=mod;
    }
}
long long query(int a){
    long long sum=0,i;
    for(i=a;i>0;i-=(i&-i)){
        sum+=fw[i];
        sum%=mod;
    }
    return sum;
}
long long query2(int d,int e){
    long long sum=0,sd=0,se=0,i;
    for(i=d;i>0;i-=(i&-i)){
        sd+=ans[i];
        sd%=mod;
    }
    for(i=e;i>0;i-=(i&-i)){
        se+=ans[i];
        se%=mod;
    }
    return (se-sd+mod)%mod;
}
int main(){
    long long n,t,q,i,a,b,c,d,e,now;
    scanf("%lld %lld %lld",&n,&t,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&a);
        mp[a]=i;
    }
    for(i=1;i<=t;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        a=mp[a];
        b=mp[b];
        update(a,c);
        update(b+1,-c);
    }
    for(i=1;i<=n;i++){
        update2(i,query(i));
        //printf("%d ",query(i));
    }
    //printf("\n");
//    for(i=1;i<=n;i++){
//        printf("%d ",query2(i-1,i));
//    }
    for(i=1;i<=q;i++){
        scanf("%lld %lld",&d,&e);
        d=mp[d];
        e=mp[e];
        now=query2(d-1,e);
        now+=mod;
        now%=mod;
        printf("%lld\n",now);
    }
}
/*
5 2 1
1 2 3 4 5
1 3 1
3 5 1
2 4
*/
