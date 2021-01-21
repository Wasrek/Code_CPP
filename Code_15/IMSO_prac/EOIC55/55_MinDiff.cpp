/*
    TASK:55_MinDiff
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int mi=2e9;
    for(i=1;i<=n-1;i++){
        if(a[i+1]-a[i]<mi)mi=a[i+1]-a[i];
    }
    printf("%d",mi);
    return 0;
}
