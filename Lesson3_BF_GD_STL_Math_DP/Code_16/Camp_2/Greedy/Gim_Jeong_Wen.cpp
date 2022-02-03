/*
    TASK:Gim Jeong Wen
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int x[5050],y[5050];
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    x[n+1]=m;
    y[n+1]=m;
    double ans1=0,ans2=0;
    for(int i=0;i<=n;i++){
        ans1=max(ans1,(double)(x[i+1]-x[i]));
        ans2=max(ans2,(double)(y[i+1]-y[i]));
    }
    ans1=min(ans1,ans2);
    // ans=1.00;
    printf("%.3lf\n",(double)(ans1/(double)2));
    return 0;
}