/*
    TASK:triangle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(n<3){
        printf("no\n");return 0;
    }
    if(a[0]+a[1]>a[n-1]) printf("no\n");
    else printf("yes\n");
    return 0;
}
