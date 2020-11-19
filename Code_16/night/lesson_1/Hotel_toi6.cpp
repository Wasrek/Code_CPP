/*
    TASK:Hotel
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int rc[5]={15,5,2,1},rw[5]={3000,1500,800,500};
int main()
{
    int n,k;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        if(n<15 && n>8){
            ans+=3000;
            printf("%lld\n",ans);
            return 0;
        }
        if(n==4){
            ans+=1500;
            printf("%lld\n",ans);
            return 0;
        }
        k=n/rc[i];
        // printf("%d %d\n",k,rc[i]);
        ans+=(k*rw[i]);
        n-=(k*rc[i]);
        // printf("%d\n",n);
    }
    printf("%lld\n",ans);
    
    return 0;
}