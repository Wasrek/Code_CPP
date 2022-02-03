/*
    TASK:RC_Organization of Justice2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
struct A{
    long long m[3][3];
};
A ma[63],ans;
A mul(A a,A b){
    long long i,j,k;
    A tmp;
    for(i=1;i<=2;i++){
        for(j=1;j<=2;j++){
            tmp.m[i][j]=0;
            for(k=1;k<=2;k++){
                tmp.m[i][j]+=a.m[i][k]*b.m[k][j];
                tmp.m[i][j]%=mod;
            }
        }
    }
    return tmp;
}
int main(){
    ma[0].m[1][2]=ma[0].m[2][1]=ma[0].m[2][2]=1;
    long long i,j;
    for(i=1;i<=60;i++){
        ma[i]=mul(ma[i-1],ma[i-1]);
    }
    long long q;
    long long n;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        ans.m[1][1]=ans.m[2][2]=1;
        ans.m[1][2]=ans.m[2][1]=0;
        for(i=0;i<60;i++){
            if(n & (1ll<<i)){
                ans=mul(ans,ma[i]);
            }
        }
        printf("%lld\n",ans.m[1][2]);
//        for(i=1;i<=2;i++){
//            for(j=1;j<=2;j++){
//                printf("%d ",ans.m[i][j]);
//            }
//            printf("\n");
//        }
    }
}
