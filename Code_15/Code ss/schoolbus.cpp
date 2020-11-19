/*
    TASK:schoolbus
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int main()
{
    int n,l=0,r=0,mid,ch,ma=0,mi=1e9,i;
    double now=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>ma)ma=a[i];
        now=max(now,(double)(ma-a[i])/2);
    }
    printf("%.6lf",now);
}
