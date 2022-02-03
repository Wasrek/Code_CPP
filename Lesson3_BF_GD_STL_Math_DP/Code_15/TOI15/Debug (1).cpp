#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i;
    long long p[10];
    bool operator<(const A&o)const{
        if(i!=o.i)  return i<o.i;
        else        return p[2]+p[3]+p[5]+p[7]<o.p[2]+o.p[3]+o.p[5]+o.p[7];
    }
};
A a[400100];
long long l[]={2,3,5,7},m;
void check(int i,int v){
    int j;
    for(j=0;j<4;j++){
        while(v%l[j]==0){
            a[i].p[l[j]]+=1;
            a[i+m].p[l[j]]+=1;
            v/=l[j];
        }
    }
}
int main(){
    long long n,i,v,st,en,j,ma=0,num,f=0;
    scanf("%lld %lld",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&v,&st,&en);
        check(i,v);
        a[i].i = st;
        a[i+m].i=en+1;
        //printf("%lld %lld %lld %lld\n",a[i].p[2],a[i].p[3],a[i].p[5],a[i].p[7]);
        for(j=0;j<4;j++){
            a[i+m].p[l[j]]*=-1;
        }
    }
    sort(a+1,a+(m*2)+1);
    for(i=1;i<=m*2;i++){
        for(j=0;j<4;j++){
            a[i].p[l[j]]+=a[i-1].p[l[j]];
            //printf("%lld ",a[i].p[l[j]]);
        }
        num=(a[i].p[2]+1)*(a[i].p[3]+1)*(a[i].p[5]+1)*(a[i].p[7]+1);
        //printf("%lld\n",num);
        if(num>ma)ma=num,f=a[i+1].i-a[i].i;
        else
        if(num==ma)f+=a[i+1].i-a[i].i;
    }
    printf("%lld %lld\n",ma,f);
}
