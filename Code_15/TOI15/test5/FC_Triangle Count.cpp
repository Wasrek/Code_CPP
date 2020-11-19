/*
    TASK:FC_Triangle Count
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
double m[300010];
int main(){
    long long n,i,a,b,c,ans,cou,m1,m2;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(b<0) b*=-1,a*=-1;
        m[i]=(double)(-1*a)/(double)(b);
        //printf("%.2lf\n",m[i]);

    }
    ans=n*(n-1)*(n-2);
    ans/=6;
    ans%=mod;
    //printf("%lld\n",ans);
    sort(m+1,m+1+n);
    cou=1;
    for(i=1;i<=n;i++){
        if(m[i]!=m[i+1] || i==n){
            m1=cou;
            m1*=(cou-1);
            m1/=2;
            m1*=(n-cou);
            m2=cou;
            m2*=(cou-1);
            m2*=(cou-2);
            m2/=6;
            ans-=(m1+m2)%mod;
            ans+=mod;
            ans%=mod;
            //printf("%lld ",cou);
            cou=1;
            continue;
        }
        cou++;
    }
    printf("%lld\n",ans);
}
/*
6
0 1 0
0 1 -3
0 1 -2
-5 3 0
-5 -2 25
-4 -5 29
*/
//20
