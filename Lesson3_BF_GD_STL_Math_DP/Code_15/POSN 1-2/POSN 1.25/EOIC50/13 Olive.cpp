/*
    TASK: Olive
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100500],b[1000050],ans[1000050];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(j=1;j<=1000000;j++)
    {
        for(k=j;k<=1000000;k+=j)
        {
            ans[k]+=b[j];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",ans[a[i]]-1);
    }
}
