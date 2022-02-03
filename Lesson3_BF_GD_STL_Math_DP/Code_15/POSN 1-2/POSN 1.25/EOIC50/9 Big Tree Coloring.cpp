#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,k,a,b,i,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(i=0;i<n-1;i++)
            scanf("%d %d",&a,&b);
        ans=k;
        for(i=0;i<n-1;i++)
            ans=(ans*(k-1))%93563;
            printf("%d\n",ans%93563);

    }
    return 0;
}
