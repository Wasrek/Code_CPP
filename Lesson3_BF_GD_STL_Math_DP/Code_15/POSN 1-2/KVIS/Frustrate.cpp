/*
    TASK:Frustrate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,i,q,x,y,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        a[i]=a[i-1]+j;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&x,&y);
        printf("%d\n",a[y]-a[x-1]);
    }

    return 0;
}
