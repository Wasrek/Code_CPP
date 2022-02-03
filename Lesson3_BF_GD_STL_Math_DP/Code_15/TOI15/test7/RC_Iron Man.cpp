/*
    TASK:RC_Iron Man
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,m,i,j,w,now,sum=0,cou=0,ma;
    scanf("%d %d",&n,&w);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(sum+a[i]<=w)cou++,sum+=a[i];
    }
    ma=cou;
    for(i=2;i<=n;i++){
        cou=0;
        sum=0;
        for(j=i;j<=n;j++){
            if(sum+a[j]<=w)cou++,sum+=a[j];
        }
        ma=max(ma,cou);
    }
    printf("%d\n",ma);
    return 0;
}

