/*
    TASK:suitable
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main()
{
    int i,n;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)
        sum+=((long long)a[i]*b[i]);
    printf("%lld\n",sum);
    return 0;
}
