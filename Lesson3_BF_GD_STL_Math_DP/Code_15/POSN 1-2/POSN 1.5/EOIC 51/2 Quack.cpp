/*
    TASK:Quack
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[44730];
int main()
{
    int i,q,n,idx;
    for(i=1;i<=44721;i++)
        a[i]=i*i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        idx = upper_bound(a,a+44722,n)-a;
    printf("%d\n",n-idx+1);
    }

    return 0;
}
