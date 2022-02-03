/*
    TASK:Matrix Expo
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[7][7];
};
long long n,c;
A mul[75],ans;
A multi(A a,A b){
    A now;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            now.a[i][j]=0;
            for(int k=1;k<=n;k++){
                now.a[i][j]+=(a.a[i][k]*b.a[k][j])%c;
                now.a[i][j]%=c;
            }
        }
    }
    return now;
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&mul[0].a[i][j]);
        }
    }
    long long b;
    scanf("%lld %lld",&b,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) ans.a[i][j]=1;
            else ans.a[i][j]=0;
        }
    }
    if(b==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%lld ",ans.a[i][j]%c);
            }
            printf("\n");
        }
        return 0;
    }
    for(int i=1;i<=61;i++){
        mul[i]=multi(mul[i-1],mul[i-1]);
    }
    for(int i=0;i<=61;i++){
        if((1ll<<i) & b){
            // printf("%d\n",i);
            ans=multi(ans,mul[i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",ans.a[i][j]);
        }
        printf("\n");
    }
    return 0;
}