/*
    TASK:AP_Bar_Chart
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],l[100010],r[100010];
int main()
{
    int q,n;
    long long ma=0;
    scanf("%d",&q);
    while(q--){
        ma=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            l[i]=i-1;
            // printf("\n--%d\n\n",i);
            while(l[i]>0 && a[i]<=a[l[i]]){
                l[i]=l[l[i]];
                // printf("%d\n",l[i]);
            }
        }
        // cout << endl;
        // for(int i=1;i<=n;i++){
        //     printf("%d ",l[i]);
        // }
        // printf("\n");
        for(int i=n;i>=1;i--){
            r[i]=i+1;
            while(r[i]<=n && a[i]<=a[r[i]]){
                r[i]=r[r[i]];
            }
        }
        // cout << endl;
        // for(int i=1;i<=n;i++){
        //     printf("%d ",r[i]);
        // }
        // printf("\n");
        for(int i=1;i<=n;i++){
            ma=max(ma,(r[i]-l[i]-1)*a[i]);
        }
        printf("%lld\n",ma);
    }   
    return 0;
}