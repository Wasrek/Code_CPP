/*
    TASK:o59_oct_c2_dslope
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9-1;
int a[80010],fw[80010][45];
void upd(int now,int k,int v){
    for(int i=now;i<80010;i+=(i&-i))fw[i][k]=((((fw[i][k]+v)%MOD)+MOD)%MOD);
}
int que(int now,int k){
    int val=0;
    for(int i=now;i>0;i-=(i&-i)) val=((((fw[i][k]+val)%MOD)+MOD)%MOD);
    return val;
}
int main()
{
    int n,k,lar;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        upd(a[i],1,1);
        for(int j=2;j<=k;j++){
            lar=((((que(n,j-1)-que(a[i],j-1))%MOD)+MOD)%MOD);
            // printf("%d %d %d\n",j,a[i],lar);
            upd(a[i],j,lar);
        }
    }
    printf("%d\n",que(n,k));
    return 0;
}