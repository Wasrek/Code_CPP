/*
    TASK:Matrix_Expo
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long mat[10][10];
};
long long b,c,n;
A a,ans;
A mop(long long p){
    if(p==1){
        return a;
    }
    long long i,j,k;
    A haf;
    A dou;
    A tri;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dou.mat[i][j]=0;
            tri.mat[i][j]=0;
        }
    }
    haf=mop(p/2);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
              dou.mat[i][j]+=haf.mat[i][k]*haf.mat[k][j];
              dou.mat[i][j]%=c;
            }
        }
    }
    if(p%2){
        for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
              tri.mat[i][j]+=dou.mat[i][k]*a.mat[k][j];
              tri.mat[i][j]%=c;
            }
        }
    }
    return tri;
    }
    else return dou;
}
int main()
{
    long long i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lld",&a.mat[i][j]);
        }
    }
    scanf("%lld %lld",&b,&c);
    if(b==0){
        for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                printf("1 ");
            }else printf("0 ");
        }
        printf("\n");
    }
    return 0;
    }
    ans=mop(b);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%lld ",ans.mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
