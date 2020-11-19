/*
    TASK: Time_Arrange
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>PII;
PII a[100100];
int main()
{
    int n,i,ans=0,last=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].second,&a[i].first);
    sort(a,a+n);
    for(i=0;i<n;i++){
        if(a[i].second >= last)
        ans++,last=a[i].first;
    }
    printf("%d\n",ans);
    return 0;
}
