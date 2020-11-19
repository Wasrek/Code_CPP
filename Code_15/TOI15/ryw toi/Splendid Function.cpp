/*
    TASK:Splendid Function
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define Mod 10000019
struct A{
    long long a[2][2];
};
A mul(A a,A b){
    A tmp;
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            tmp.a[i][j]=0;
            for(k=0;k<2;k++){
                tmp.a[i][j]+=(a.a[i][k]*b.a[k][j]);
                tmp.a[i][j]%=Mod;
            }
        }
    }
    return tmp;
}
A m[50],ans;
int main(){
    long long q,n,i;
    m[0]={1,1,1,0};
    for(i=1;i<=42;i++)
        m[i]=mul(m[i-1],m[i-1]);
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans={1,0,0,1};
        for(i=0;i<=42;i++){
            if(n & (1ll<<i))
                ans=mul(ans,m[i]);
        }
        printf("%lld\n",ans.a[0][1]);
    }
    return 0;
}
