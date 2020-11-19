/*
    TASK:Swift Root Two
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[4][4];
} ;
long long x;
A mul(A a,A b){
    A tmp;
    int i,j,k;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            tmp.a[i][j]=0;
            for(k=0;k<4;k++){
//                printf("%d %d %d\n",i,j,k);
                tmp.a[i][j]+=(a.a[i][k]*b.a[k][j])%x;
                tmp.a[i][j]%=x;
            }
        }
    }
    return tmp;
}
A ans;
A m[35];
int main(){
    long long q,a,b,c,n,i,j;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&n,&x);
        m[0]={a,b,c,0,2*b,a,0,c,3*c,0,a,b,0,3*c,2*b,a};
        for(i=1;i<=30;i++){
            m[i]=mul(m[i-1],m[i-1]);
        }
        memset(ans.a,0,sizeof ans.a);
        for(i=0;i<4;i++){
            ans.a[i][i]=1;
        }
        for(i=0;i<=30;i++){
            if((1ll<<i) & n){
                ans=mul(ans,m[i]);
            }
        }
        for(i=0;i<4;i++){
            printf("%lld ",ans.a[0][i]);
        }
        printf("\n");
    }
}
