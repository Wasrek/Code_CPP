/*
    TASK:Plate Sort
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main()
{
    int q,n,h,cnt,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==n)h=i;
        }
        now=n;cnt=0;
        for(int i=h;i>0;i--){
            if(a[i]==now){
                cnt++;
                now--;
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}