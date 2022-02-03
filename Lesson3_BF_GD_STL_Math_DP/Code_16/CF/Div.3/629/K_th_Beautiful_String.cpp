/*
    TASK:K-th Beautiful String
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[100010];
int main()
{
    long long q,n,k,lb,f,s,all=100000;
    scanf("%lld",&q);
    for(int i=1;i<=100000;i++){
        qs[i]=qs[i-1]+i;
        // printf("%d ",qs[i]);
        // if(qs[i]+i+1>2000000000){all=i;break;}
    }
    // printf("%lld\n",qs[all]);
    // lb=lower_bound(qs,qs+1+all,2000000000)-qs;
    // printf("%d %d\n",lb,qs[lb]);
    while(q--){
        scanf("%lld %lld",&n,&k);
        lb=lower_bound(qs,qs+1+all,k)-qs;
        // printf("%d %d\n",lb,qs[lb]);
        f=lb+1;
        s=k-qs[lb-1];
        // printf("%d %d\n",f,s);
        for(int i=n;i>=1;i--){
            if(i!=f && i!=s){
                printf("a");
            }else printf("b");
        }
        printf("\n");
    }
    return 0;
}