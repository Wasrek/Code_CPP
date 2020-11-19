/*
    TASK:Slip Triangle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
    int n,i,j;
    scanf(" %d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        scanf("%d",&a[i][j]);
    for(i=n;i>=1;i--){
        for(j=1;j<=i;j++){
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d\n",a[1][1]);

    return 0;
}
