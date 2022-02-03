/*
    TASK:RT_Employee
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    double m[251][251];
};
int n;
A tmp;
void mul(A *a,A *b){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            tmp.m[i][j]=0;
            for(k=1;k<=n;k++){
                tmp.m[i][j]+=a->m[i][k]*b->m[k][j];
            }
        }
    }
}
A dp[20],ans,mat;
int main(){
    int t,i,j;
    scanf("%d %d",&n,&t);
    for(i=1;i<=n;i++){
        scanf("%lf",&ans.m[i][1]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lf",&dp[0].m[j][i]);
        }
    }
    for(i=1;i<20;i++){
        mul(&dp[i-1],&dp[i-1]);
        dp[i]=tmp;
    }
    for(i=1;i<=n;i++)mat.m[i][i]=1;
    for(i=0;i<20;i++){
        if(t&(1ll<<i)){
            mul(&mat,&dp[i]);
            mat=tmp;
        }
    }
    mul(&mat,&ans);
    ans=tmp;
    for(i=1;i<=n;i++)printf("%.2lf\n",ans.m[i][1]);
    return 0;
}
/*
3 1
30 40 50
0.5 0.2 0.3
0.1 0.4 0.5
0.3 0.3 0.4
*/
