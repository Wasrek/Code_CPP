/*
    TASK:RT_Ways
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 10000019
struct A{
    long long a[7][7];
};
A m[65];
A mul(A a, A b){
    A tmp;
    long long i,j,k;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp.a[i][j]=0;
            for(k=0;k<4;k++){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=mod;
            }
        }
    }
    return tmp;
}
A ans;
int main(){
    long long q,n,i;
    m[0]={{{0,0,1,0},{1,0,1,0},{0,0,0,1},{0,1,0,0}}};
    for(i=1;i<60;i++){
        m[i]=mul(m[i-1],m[i-1]);
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        n--;
        memset(ans.a,0,sizeof ans.a);
        for(i=0;i<4;i++)
        ans.a[i][i]=1;
        for(i=0;i<=60;i++){
            if(((1ll)<<i) & n){
                ans=mul(ans,m[i]);
            }
        }
        for(i=0;i<4;i++){
            printf("%d ",ans.a[i][0]);
        }
        printf("\n");
    }
}
