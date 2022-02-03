/*
    TASK:Roam
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,q,k,s,e,i,l;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d %d",&s,&e);
        a[s]++;a[e+1]--;
    }
    scanf("%d",&k);
    for(i=1;i<=n;i++)a[i]+=a[i-1];
    while(k--){
        scanf("%d",&l);
        printf("%d\n",a[l]);
    }

    return 0;
}
