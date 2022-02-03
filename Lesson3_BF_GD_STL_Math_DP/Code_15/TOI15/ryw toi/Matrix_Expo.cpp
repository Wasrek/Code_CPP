/*
    TASK:Matrix_Expo
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[7][7];
};
long long n,mod;
A mul(A a,A b){
    A tmp;
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tmp.a[i][j]=0;
            for(k=0;k<n;k++){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=mod;
            }
        }
    }
    return tmp;
}
A m[65],ans;
int main(){
    long long i,j,b;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lld",&ans.a[i][j]);
        }
    }
    scanf("%lld %lld",&b,&mod);
    if(b==0){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf((i==j)?"1":"0");
            }
            printf("\n");
        }
        return 0;
    }
    m[0]=ans;
    for(i=1;i<=61;i++)
        m[i]=mul(m[i-1],m[i-1]);
    b--;
    for(i=0;i<=61;i++){
        if((1ll<<i) & b)
        ans=mul(ans,m[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",ans.a[i][j]);
        }printf("\n");
    }
    return 0;
}
/*
2
5 8
21 6
2 100
*/
