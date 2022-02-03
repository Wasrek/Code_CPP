/*
    TASK:Entertain
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[5050],mark[5050];
int main()
{
    int i,j,n,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]),a[i]--;
    for(i=1;i<n;i++){
        if(mark[i]) continue;
        ans++;
        for(j=i+1;j<n;j++)
            if(a[j]%a[i]==0)
            mark[j]=1;
    }
    printf("%d\n",ans);
    return 0;
}
