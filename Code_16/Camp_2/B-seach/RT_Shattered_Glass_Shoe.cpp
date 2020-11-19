/*
    TASK:RT_Shattered Glass Shoe
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],h[100010];
int main()
{
    int n,f;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    scanf("%d",&f);
    int l=0,r=2e9;
    long long wa;
    while(l<r){
        int mid=(l+r+1)/2;
        wa=0;
        for(int i=1;i<=n;i++){
            if((mid*a[i])<=h[i])continue;
            wa+=(mid*a[i])-h[i];
        }
        if(wa<=f)l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}